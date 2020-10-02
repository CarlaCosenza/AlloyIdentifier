#include "addtodatabase.h"
#include "ui_addtodatabase.h"

AddToDatabase::AddToDatabase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddToDatabase)
{
    ui->setupUi(this);
}

AddToDatabase::~AddToDatabase()
{
    delete ui;
}
