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

    EnumOperator();
    QString alloyClassToString(AlloyClass alloyClass);
};

#endif // ENUMOPERATOR_H
