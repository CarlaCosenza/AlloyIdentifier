#ifndef ADDTODATABASE_H
#define ADDTODATABASE_H

#include <QDialog>
#include <QDoubleValidator>

#include "enumoperator.h"
#include "databasemanager.h"

namespace Ui {
class AddToDatabase;
}

class AddToDatabase : public QDialog
{
    Q_OBJECT

public:
    explicit AddToDatabase(QWidget *parent = nullptr);
    ~AddToDatabase();

private slots:
    void on_addToDatabase_clicked();

private:
    Ui::AddToDatabase *ui;
    QDoubleValidator *dblVal;
    EnumOperator enumOp;
    DatabaseManager databaseManager;

    void setLineEditValidators();
    void setUpComboBox();
    void clearAllLineEdits();
    QString getElementFromInputName(QString inputName);
    QString getInputTypeFromInputName(QString inputName);
    Alloy createAlloy();
    void showErrorMessage(QString message);
};

#endif // ADDTODATABASE_H
