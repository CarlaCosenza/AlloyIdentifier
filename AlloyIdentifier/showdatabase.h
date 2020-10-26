#ifndef SHOWDATABASE_H
#define SHOWDATABASE_H

#include <QDialog>

#include "databasemanager.h"

namespace Ui {
class ShowDatabase;
}

class ShowDatabase : public QDialog
{
    Q_OBJECT

public:
    explicit ShowDatabase(QWidget *parent = nullptr);
    ~ShowDatabase();

private:
    Ui::ShowDatabase *ui;
    DatabaseManager databaseManager;
    EnumOperator enumOp;

    void setUpTable();
    void showErrorMessage(QString message);
    QStringList createHeader();
};

#endif // SHOWDATABASE_H
