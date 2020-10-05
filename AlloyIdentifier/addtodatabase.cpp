#include <QMessageBox>

#include "addtodatabase.h"
#include "ui_addtodatabase.h"

AddToDatabase::AddToDatabase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddToDatabase)
{
    ui->setupUi(this);
    this->setLineEditValidators();
}

AddToDatabase::~AddToDatabase(){
    delete ui;
}

void AddToDatabase::on_addToDatabase_clicked()
{
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
        QMessageBox::warning(this, "Test", str);
    }
}
