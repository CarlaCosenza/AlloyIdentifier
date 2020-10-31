#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QFile>
#include <QTableWidget>
#include <queue>

#include "alloy.h"

using namespace std;


class DatabaseManager
{
public:
    DatabaseManager();
    bool writeAlloyToDatabase(Alloy alloy);
    bool buildTableWithDatabase(QTableWidget* table);
    priority_queue< pair<double, Alloy> > compareAlloyWithDatabase(Alloy alloy);
    QString parseAlloyForDatabase(Alloy alloy);

private:
    static const QString databaseFileName;
    EnumOperator enumOp;

    Alloy parseAlloyFromDatabase(QString alloyLine);
};

#endif // DATABASEMANAGER_H
