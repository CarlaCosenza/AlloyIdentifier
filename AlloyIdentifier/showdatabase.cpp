#include "showdatabase.h"
#include "ui_showdatabase.h"

#include <QMessageBox>
#include <QHeaderView>

ShowDatabase::ShowDatabase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowDatabase)
{
    this->databaseManager = DatabaseManager();
    this->enumOp = EnumOperator();

    ui->setupUi(this);
    this->setUpTable();
}

ShowDatabase::~ShowDatabase()
{
    delete ui;
}

void ShowDatabase::setUpTable(){
    bool buildTable = this->databaseManager.buildTableWithDatabase(this->ui->table);
    if(buildTable == false){
        return this->showErrorMessage("There was a problem accessing the database.");
    }

    this->ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->ui->table->verticalHeader()->setVisible(false);

    QStringList headers = this->createHeader();
    this->ui->table->setHorizontalHeaderLabels(headers);
}

void ShowDatabase::showErrorMessage(QString message){
    QMessageBox::warning(this, "Warning", message);
}

QStringList ShowDatabase::createHeader(){
    QStringList headers;
    headers << "Nome" << "Classe";
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
