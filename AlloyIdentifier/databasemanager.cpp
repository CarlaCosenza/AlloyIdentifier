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

Alloy DatabaseManager::parseAlloyFromDatabase(QString alloyLine){
    auto values = alloyLine.split(",");

    QString name = values[0];
    QString classString = values[1];
    AlloyClass alloyClass = enumOp.stringToAlloyClass(classString);

    Alloy alloy = Alloy(name, alloyClass);

    for(int i = 2 ; i < values.size() ; i++){
        Elements el = static_cast<Elements>((i-2)/3);
        if((i-2)%3 == 0){
            alloy.editComposition(el, "min", values[i].toDouble());
        }
        if((i-2)%3 == 1){
            alloy.editComposition(el, "max", values[i].toDouble());
        }
        if((i-2)%3 == 2){
            alloy.editComposition(el, "spec", values[i].toDouble());
        }
    }

    return alloy;
}

priority_queue< pair<double, Alloy> > DatabaseManager::compareAlloyWithDatabase(Alloy alloy){
    priority_queue< pair<double, Alloy> > queue;

    QFile file(this->databaseFileName);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        return queue;
    }
    QTextStream in(&file);

    while (!in.atEnd()){
        QString line = in.readLine();
        Alloy alloyFromDatabase = this->parseAlloyFromDatabase(line);
        if(alloyFromDatabase.isComparable(alloy)){
            double totalDistance = 0;
            for(int i = MAGNESIUM ; i <= CARBON ; i++){
                Elements el = static_cast<Elements>(i);
                if(alloy.getCompositionOfElement(el).getSpec() == -1 ) continue;

                double distance = abs(alloy.getCompositionOfElement(el).getSpec() - alloyFromDatabase.getCompositionOfElement(el).getSpec());
                distance = distance/(alloyFromDatabase.getCompositionOfElement(el).getMax() - alloyFromDatabase.getCompositionOfElement(el).getMin());
                totalDistance = totalDistance + distance;
            }
            queue.push({-totalDistance, alloyFromDatabase});
        }
    }

    file.close();

    return queue;
}
