#include "home.h"
#include "ui_home.h"
#include "showdatabase.h"
#include "addtodatabase.h"

Home::Home(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Home)
{
    ui->setupUi(this);
}

Home::~Home()
{
    delete ui;
}

void Home::on_buttonShowDatabase_clicked()
{
    ShowDatabase showDatabase(this);
    showDatabase.setModal(true);
    hide();
    showDatabase.exec();
    show();
}

void Home::on_buttonEditDatabase_clicked()
{
    AddToDatabase addToDatabase(this);
    addToDatabase.setModal(true);
    hide();
    addToDatabase.exec();
    show();
}
