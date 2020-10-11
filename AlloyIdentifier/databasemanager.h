#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QFile>

#include "alloy.h"


class DatabaseManager
{
public:
    DatabaseManager();
    bool writeAlloyToDatabase(Alloy alloy);

private:
    static const QString databaseFileName;
    EnumOperator enumOp;

    QString parseAlloyForDatabase(Alloy alloy);
};

#endif // DATABASEMANAGER_H
