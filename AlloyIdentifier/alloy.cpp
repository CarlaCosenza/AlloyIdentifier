#include "alloy.h"

Alloy::Alloy(QString name, AlloyClass alloyClass){
    this->name = name;
    this->alloyClass = alloyClass;
}

void Alloy::addElement(Elements element, Composition composition){
    this->elementComposition[element] = composition;
}
