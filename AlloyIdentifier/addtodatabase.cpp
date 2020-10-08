#include <QMessageBox>
#include <QDebug>

#include "addtodatabase.h"
#include "ui_addtodatabase.h"

AddToDatabase::AddToDatabase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddToDatabase)
{
    this->enumOp = EnumOperator();

    ui->setupUi(this);
    this->setLineEditValidators();
    this->setUpComboBox();
}

AddToDatabase::~AddToDatabase(){
    delete ui;
}

void AddToDatabase::on_addToDatabase_clicked(){
    this->createAlloy();
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
}

void AddToDatabase::clearAllLineEdits(){
    const QList<QLineEdit*> lineEdits = this->ui->compositionFrame->findChildren<QLineEdit*>();
    for (QLineEdit *lineEdit : lineEdits) {
        lineEdit->clear();
    }
}

void AddToDatabase::createAlloy(){
    QString str = this->ui->inputName->text();
    QMessageBox::warning(this, "Test", str);
    const QList<QLineEdit*> lineEdits = this->ui->compositionFrame->findChildren<QLineEdit*>();
    for (QLineEdit *lineEdit : lineEdits) {
        str = lineEdit->objectName();
        qDebug() << "teste" << str;
//        QMessageBox::warning(this, "Test", str);
    }
}
