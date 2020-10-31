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

map<QString, AlloyClass> EnumOperator::namesAlloyClass = {
    {"Alumínios", ALUMINIOS},
    {"Aços inox", ACOS_INOX},
    {"Cobre", COBRE},
    {"Ligas de carbono", LIGAS_DE_CARBONO},
    {"Aço ferramenta", ACO_FERRAMENTA},
    {"Outros", OUTROS}
};

map<Elements, QString> EnumOperator::elementNames = {
    {MAGNESIUM, "Mg"},
    {ALUMINIUM, "Al"},
    {SILICON, "Si"},
    {TITANIUM, "Ti"},
    {VANADIUM, "V"},
    {CHROMIUM, "Cr"},
    {MANGANESE, "Mn"},
    {IRON, "Fe"},
    {COBALT, "Co"},
    {NICKEL, "Ni"},
    {COPPER, "Cu"},
    {ZINC, "Zn"},
    {MOLYBDENUM, "Mo"},
    {TIN, "Sn"},
    {TUNGSTEN, "W"},
    {PALLADIUM, "Pb"},
    {CARBON, "C"}
};

map<QString, Elements> EnumOperator::namesElements = {
    {"mg", MAGNESIUM},
    {"al", ALUMINIUM},
    {"si", SILICON},
    {"ti", TITANIUM},
    {"v", VANADIUM},
    {"cr", CHROMIUM},
    {"mn", MANGANESE},
    {"fe", IRON},
    {"co", COBALT},
    {"ni", NICKEL},
    {"cu", COPPER},
    {"zn", ZINC},
    {"mo", MOLYBDENUM},
    {"sn", TIN},
    {"w", TUNGSTEN},
    {"pb", PALLADIUM},
    {"c", CARBON}
};

QString EnumOperator::alloyClassToString(AlloyClass alloyClass){
    return this->alloyClassNames[alloyClass];
}

AlloyClass EnumOperator::stringToAlloyClass(QString alloyClassString){
    return this->namesAlloyClass[alloyClassString];
}

QString EnumOperator::elementToString(Elements element){
    return this->elementNames[element];
}

Elements EnumOperator::stringToElement(QString elementString){
    return this->namesElements[elementString];
}
