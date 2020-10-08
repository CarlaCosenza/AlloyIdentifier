#include "enumoperator.h"

using namespace std;

EnumOperator::EnumOperator(){}

map<AlloyClass, QString> EnumOperator::alloyClassNames = {
    {ALUMINIOS, "Alumínios"},
    {ACOS_INOX, "Aços inox"},
    {COBRE, "Cobre"},
    {LIGAS_DE_CARBONO, "Ligas de carbono"},
    {ACO_FERRAMENTA, "Aço ferramenta"},
    {OUTROS, "Outros"}
};

QString EnumOperator::alloyClassToString(AlloyClass alloyClass){
    return this->alloyClassNames[alloyClass];
}

