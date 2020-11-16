#include "compare.h"
#include "ui_compare.h"

#include <QDebug>

compare::compare(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::compare)
{
    this->enumOp = EnumOperator();
    this->databaseManager = DatabaseManager();

    ui->setupUi(this);
    this->setUpComboBox();
}

compare::~compare()
{
    delete ui;
}

void compare::setLineEditValidators(){
    this->dblVal = new QDoubleValidator(0, 100, 10);
    this->dblVal->setNotation(QDoubleValidator::StandardNotation);
    this->dblVal->setLocale(QLocale::C);

    const QList<QLineEdit*> lineEdits = this->ui->formFrame->findChildren<QLineEdit*>();
    for (QLineEdit *lineEdit : lineEdits) {
        lineEdit->setValidator(this->dblVal);
    }
}


void compare::setUpComboBox(){
    for(int i = ANY ; i <= OUTROS ; i++){
        this->ui->classeInput->addItem(this->enumOp.alloyClassToString(static_cast<AlloyClass>(i)));
    }
}

void compare::on_compareAlloy_clicked(){
    Alloy alloy = this->createAlloy();
    alloy.printAlloy();
    priority_queue< pair<double, Alloy> > queue = this->databaseManager.compareAlloyWithDatabase(alloy);

    this->printResultTable(queue);
}

QString compare::getElementFromInputName(QString inputName){
    if(inputName.contains("Spec")){
        inputName.chop(4);
    }
    else{
        inputName.chop(3);
    }
    return inputName;
}

QString compare::getInputTypeFromInputName(QString inputName){
    if(inputName.contains("Min")){
        return "min";
    }
    if(inputName.contains("Max")){
        return "max";
    }
    return "spec";
}

Alloy compare::createAlloy(){
    QString alloyName = "testingAlloy";
    int classId = this->ui->classeInput->currentIndex();
    AlloyClass alloyClass = static_cast<AlloyClass>(classId);
    Alloy alloy = Alloy(alloyName, alloyClass);

    QString inputName;
    const QList<QLineEdit*> lineEdits = this->ui->formFrame->findChildren<QLineEdit*>();
    for (QLineEdit *lineEdit : lineEdits) {
        inputName = lineEdit->objectName();
        QString stringValue = lineEdit->text();
        if(stringValue == "") continue;
        double value = stringValue.toDouble();
        QString elementString = this->getElementFromInputName(inputName);
        Elements element = this->enumOp.stringToElement(elementString);

        alloy.editComposition(element, "spec", value);
    }

    return alloy;
}

void compare::printResultTable(priority_queue< pair <double, Alloy> > queue){

    if(queue.empty()){
        this->ui->table->setRowCount(1);
        this->ui->table->setColumnCount(1);
        this->ui->table->setItem(0, 0, new QTableWidgetItem("Não encontrado"));

        return;
    }

    int rowCount = 0;

    while(!queue.empty() and rowCount < 6){
        Alloy alloy = queue.top().second;
        queue.pop();

        QString alloyString = this->databaseManager.parseAlloyForDatabase(alloy);
        alloyString.chop(1);
        auto values = alloyString.split(",");

        int columnCount = values.size();
        this->ui->table->setRowCount(rowCount+1);
        this->ui->table->setColumnCount(columnCount - 1);
        this->ui->table->setItem(rowCount, 0, new QTableWidgetItem(values[0]));
        for(int j = 2 ; j < columnCount ; j++){
            if(values[j] == "-1"){
                this->ui->table->setItem(rowCount, j-1, new QTableWidgetItem("0"));
            }
            else this->ui->table->setItem(rowCount, j-1, new QTableWidgetItem(values[j]));
        }
        rowCount++;
    }

    this->ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->ui->table->verticalHeader()->setVisible(false);

    QStringList headers = this->createHeader();
    this->ui->table->setHorizontalHeaderLabels(headers);
}

QStringList compare::createHeader(){
    QStringList headers;
    headers << "Nome";
    for(int i = MAGNESIUM ; i <= CARBON ; i++){
        Elements el = static_cast<Elements>(i);
        QString elementName = enumOp.elementToString(el);
        QString min = elementName + " min";
        QString max = elementName + " max";
        QString spec = elementName + " spec";
        headers << min << max << spec;
    }

    return headers;
}
