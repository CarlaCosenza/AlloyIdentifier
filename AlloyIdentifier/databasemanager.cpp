#include "databasemanager.h"
#include "userData.h"

#include <QMessageBox>
#include <QTextStream>
#include <QDebug>

const QString DatabaseManager::databaseFileName = databasePath;

DatabaseManager::DatabaseManager(){
    this->enumOp = EnumOperator();
}

bool DatabaseManager::writeAlloyToDatabase(Alloy alloy){
    QFile file(this->databaseFileName);
    if(!file.open(QFile::Append | QFile::Text)){
        return false;
    }
    QString parsedAlloy = this->parseAlloyForDatabase(alloy);

    QTextStream out(&file);
    out << parsedAlloy;

    file.flush();
    file.close();

    return true;
}

QString DatabaseManager::parseAlloyForDatabase(Alloy alloy){
    QString parsedAlloy = alloy.getName();
    parsedAlloy.append(",");
    AlloyClass alloyClass = alloy.getAlloyClass();
    parsedAlloy.append(enumOp.alloyClassToString(alloyClass));
    parsedAlloy.append(",");
    for(int i = MAGNESIUM ; i <= CARBON ; i++) {
        Elements el = static_cast<Elements>(i);
        Composition composition = alloy.getCompositionOfElement(el);
        parsedAlloy.append(QString::number(composition.getMin()));
        parsedAlloy.append(",");
        parsedAlloy.append(QString::number(composition.getMax()));
        parsedAlloy.append(",");
        parsedAlloy.append(QString::number(composition.getSpec()));
        parsedAlloy.append(",");
    }

    parsedAlloy.chop(1);
    parsedAlloy.append("\n");

    return parsedAlloy;
}

bool DatabaseManager::buildTableWithDatabase(QTableWidget *table){
    QFile file(this->databaseFileName);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        return false;
    }
    QTextStream in(&file);

    int rowCount = 0;
    while(!in.atEnd()){
        table->setRowCount(rowCount+1);
        auto line = in.readLine();
        auto values = line.split(",");
        int columnCount = values.size();
        table->setColumnCount(columnCount);
        for(int j = 0 ; j < columnCount ; j++){
            table->setItem(rowCount, j, new QTableWidgetItem(values[j]));
        }
        rowCount++;
    }

    file.close();

    return true;
}
