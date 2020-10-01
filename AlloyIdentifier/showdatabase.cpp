#include "showdatabase.h"
#include "ui_showdatabase.h"

ShowDatabase::ShowDatabase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowDatabase)
{
    ui->setupUi(this);
}

ShowDatabase::~ShowDatabase()
{
    delete ui;
}
