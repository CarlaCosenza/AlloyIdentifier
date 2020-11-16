#ifndef ENUMOPERATOR_H
#define ENUMOPERATOR_H

#include <QString>

#include <map>

using namespace std;

typedef enum Elements {
    MAGNESIUM,
    ALUMINIUM,
    SILICON,
    TITANIUM,
    VANADIUM,
    CHROMIUM,
    MANGANESE,
    IRON,
    COBALT,
    NICKEL,
    COPPER,
    ZINC,
    MOLYBDENUM,
    TIN,
    TUNGSTEN,
    PALLADIUM,
    CARBON,
} Elements;

typedef enum AlloyClass {
    ANY,
    ALUMINIOS,
    ACOS_INOX,
    COBRE,
    LIGAS_DE_CARBONO,
    ACO_FERRAMENTA,
    OUTROS,
} AlloyClass;

class EnumOperator
{
public:
    static map<AlloyClass, QString> alloyClassNames;
    static map<QString, AlloyClass> namesAlloyClass;
    static map<Elements, QString> elementNames;
    static map<QString, Elements> namesElements;

    EnumOperator();
    QString alloyClassToString(AlloyClass alloyClass);
    AlloyClass stringToAlloyClass(QString alloyClassString);
    QString elementToString(Elements element);
    Elements stringToElement(QString elementString);
};

#endif // ENUMOPERATOR_H
