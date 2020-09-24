#ifndef SHOWDATABASE_H
#define SHOWDATABASE_H

#include <QDialog>

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
};

#endif // SHOWDATABASE_H
