#ifndef ALLOY_H
#define ALLOY_H

#import <QString>
#import <map>
#import "composition.h"

using namespace std;

typedef enum AlloyClass {
    ALUMINIOS,
    ACOS_INOX,
    COBRE,
    LIGAS_DE_CARBONO,
    ACO_FERRAMENTA,
    OUTROS,
} AlloyClass;


class Alloy
{
private:
    QString name;
    AlloyClass alloyClass;
    map <Elements, Composition> elementComposition;

public:
    Alloy(QString name, AlloyClass alloyClass);
    void addElement(Elements element, Composition composition);
};

#endif // ALLOY_H
