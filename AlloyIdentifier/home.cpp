#include "home.h"
#include "ui_home.h"
#include "showdatabase.h"

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
