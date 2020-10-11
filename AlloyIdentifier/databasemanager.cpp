#include "databasemanager.h"

#include <QMessageBox>
#include <QTextStream>
#include <QDebug>

const QString DatabaseManager::databaseFileName = "database.csv";

DatabaseManager::DatabaseManager(){
    this->enumOp = EnumOperator();
}

bool DatabaseManager::writeAlloyToDatabase(Alloy alloy){
    QFile file(this->databaseFileName);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        return false;
    }
    QString parsedAlloy = this->parseAlloyForDatabase(alloy);

    QTextStream out(&file);
    out << parsedAlloy;

    file.flush();
    file.close();

    QFile filee(this->databaseFileName);
    if(!file.open(QFile::ReadOnly |
                  QFile::Text))
    {
        qDebug() << " Could not open the file for reading";
        return false;
    }

    QTextStream in(&filee);
    QString myText = in.readAll();
    qDebug() << myText;

    filee.close();

    return true;
}

QString DatabaseManager::parseAlloyForDatabase(Alloy alloy){
    QString parsedAlloy = alloy.getName();
    parsedAlloy.append(", ");
    AlloyClass alloyClass = alloy.getAlloyClass();
    parsedAlloy.append(enumOp.alloyClassToString(alloyClass));
    parsedAlloy.append(", ");
    for(int i = MAGNESIUM ; i <= CARBON ; i++) {
        Elements el = static_cast<Elements>(i);
        Composition composition = alloy.getCompositionOfElement(el);
        parsedAlloy.append(QString::number(composition.getMin()));
        parsedAlloy.append(", ");
        parsedAlloy.append(QString::number(composition.getMax()));
        parsedAlloy.append(", ");
        parsedAlloy.append(QString::number(composition.getSpec()));
        parsedAlloy.append(", ");
    }
    parsedAlloy.chop(2);

    return parsedAlloy;
}
