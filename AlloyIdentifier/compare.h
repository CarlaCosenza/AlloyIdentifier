#ifndef COMPARE_H
#define COMPARE_H

#include <QDialog>

#include "enumoperator.h"
#include "alloy.h"
#include "databasemanager.h"

namespace Ui {
class compare;
}

class compare : public QDialog
{
    Q_OBJECT

public:
    explicit compare(QWidget *parent = nullptr);
    ~compare();

private slots:
    void on_compareAlloy_clicked();

private:
    Ui::compare *ui;
    QDoubleValidator *dblVal;
    EnumOperator enumOp;
    DatabaseManager databaseManager;

    void setUpComboBox();
    void setLineEditValidators();
    Alloy createAlloy();
    QString getElementFromInputName(QString inputName);
    QString getInputTypeFromInputName(QString inputName);
    void printResultTable(priority_queue< pair <double, Alloy> > queue);
};

#endif // COMPARE_H
