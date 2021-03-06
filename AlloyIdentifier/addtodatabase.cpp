#include <QMessageBox>
#include <QDebug>

#include "addtodatabase.h"
#include "ui_addtodatabase.h"
#include "alloy.h"

AddToDatabase::AddToDatabase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddToDatabase)
{
    this->enumOp = EnumOperator();
    this->databaseManager = DatabaseManager();

    ui->setupUi(this);
    this->setLineEditValidators();
    this->setUpComboBox();
}

AddToDatabase::~AddToDatabase(){
    delete ui;
}

void AddToDatabase::on_addToDatabase_clicked(){
    Alloy alloy = this->createAlloy();
    if(alloy.verifyAlloy() == false){
        return this->showErrorMessage("The added alloy was malformated.");
    }

    bool addedToDatabase = this->databaseManager.writeAlloyToDatabase(alloy);
    if(addedToDatabase == false){
        return this->showErrorMessage("There was an error saving to the database.");
    }

    QMessageBox::information(this, "Success!", "Alloy added with success");
    this->clearAllLineEdits();
}

void AddToDatabase::setLineEditValidators(){
    this->dblVal = new QDoubleValidator(0, 100, 10);
    this->dblVal->setNotation(QDoubleValidator::StandardNotation);
    this->dblVal->setLocale(QLocale::C);

    const QList<QLineEdit*> lineEdits = this->ui->compositionFrame->findChildren<QLineEdit*>();
    for (QLineEdit *lineEdit : lineEdits) {
        lineEdit->setValidator(this->dblVal);
    }
}

void AddToDatabase::setUpComboBox(){
    for(int i = ALUMINIOS ; i <= OUTROS ; i++){
        this->ui->classeInput->addItem(this->enumOp.alloyClassToString(static_cast<AlloyClass>(i)));
    }

    this->ui->restanteInput->addItem("Nenhum");
    this->ui->restanteInput->addItem(this->enumOp.elementToString(static_cast<Elements>(ALUMINIUM)));
    this->ui->restanteInput->addItem(this->enumOp.elementToString(static_cast<Elements>(IRON)));
    this->ui->restanteInput->addItem(this->enumOp.elementToString(static_cast<Elements>(COPPER)));
}

void AddToDatabase::clearAllLineEdits(){
    const QList<QLineEdit*> lineEdits = this->ui->compositionFrame->findChildren<QLineEdit*>();
    for (QLineEdit *lineEdit : lineEdits) {
        lineEdit->clear();
    }
    this->ui->inputName->clear();
}

QString AddToDatabase::getElementFromInputName(QString inputName){
    if(inputName.contains("Spec")){
        inputName.chop(4);
    }
    else{
        inputName.chop(3);
    }
    return inputName;
}

QString AddToDatabase::getInputTypeFromInputName(QString inputName){
    if(inputName.contains("Min")){
        return "min";
    }
    if(inputName.contains("Max")){
        return "max";
    }
    return "spec";
}

Alloy AddToDatabase::createAlloy(){
    QString alloyName = this->ui->inputName->text();
    int classId = this->ui->classeInput->currentIndex();
    AlloyClass alloyClass = static_cast<AlloyClass>(classId);
    Alloy alloy = Alloy(alloyName, alloyClass);
    double totalMin = 0;
    double totalMax = 0;

    QString inputName;
    const QList<QLineEdit*> lineEdits = this->ui->compositionFrame->findChildren<QLineEdit*>();
    for (QLineEdit *lineEdit : lineEdits) {
        inputName = lineEdit->objectName();
        QString stringValue = lineEdit->text();
        if(stringValue == "") continue;
        double value = stringValue.toDouble();
        QString inputType = this->getInputTypeFromInputName(inputName);
        QString elementString = this->getElementFromInputName(inputName);
        Elements element = this->enumOp.stringToElement(elementString);

        if(inputType == "min") totalMin = totalMin + value;
        if(inputType == "max") totalMax = totalMax + value;

        alloy.editComposition(element, inputType, value);
    }

    QString restante = this->ui->restanteInput->currentText();
    if(restante != "Nenhum"){
        restante = restante.toLower();
        Elements element = this->enumOp.stringToElement(restante);
        alloy.editComposition(element, "min", 100 - totalMax);
        alloy.editComposition(element, "max", 100 - totalMin);
    }

    alloy.fillValuesAlloy();
    return alloy;
}

void AddToDatabase::showErrorMessage(QString message){
    QMessageBox::warning(this, "Warning", message);
}
