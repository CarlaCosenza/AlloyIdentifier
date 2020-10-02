#ifndef ADDTODATABASE_H
#define ADDTODATABASE_H

#include <QDialog>

namespace Ui {
class AddToDatabase;
}

class AddToDatabase : public QDialog
{
    Q_OBJECT

public:
    explicit AddToDatabase(QWidget *parent = nullptr);
    ~AddToDatabase();

private:
    Ui::AddToDatabase *ui;
};

#endif // ADDTODATABASE_H
