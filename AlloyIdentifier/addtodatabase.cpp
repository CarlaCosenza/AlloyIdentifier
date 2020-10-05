#include "addtodatabase.h"
#include "ui_addtodatabase.h"

AddToDatabase::AddToDatabase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddToDatabase)
{
    ui->setupUi(this);
}

AddToDatabase::~AddToDatabase(){
    delete ui;
}

void AddToDatabase::clearAllLineEdits(){
    const QList<QLineEdit*> lineEdits = this->ui->compositionFrame->findChildren<QLineEdit*>();
    for (QLineEdit *lineEdit : lineEdits) {
        lineEdit->clear();
    }
}

void AddToDatabase::on_addToDatabase_clicked()
{
    this->clearAllLineEdits();
}
