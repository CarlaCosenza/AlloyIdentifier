#ifndef ADDTODATABASE_H
#define ADDTODATABASE_H

#include <QDialog>
#include <QDoubleValidator>

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

    void setLineEditValidators();
    void clearAllLineEdits();
    void createAlloy();
};

#endif // ADDTODATABASE_H
