#include "alloy.h"

#include <QDebug>

Alloy::Alloy(QString name, AlloyClass alloyClass){
    this->name = name;
    this->alloyClass = alloyClass;
    this->enumOp = EnumOperator();

    map <Elements, Composition> elementComposition;
    for(int i = MAGNESIUM ; i <= CARBON ; i++){
        Composition composition = Composition();
        Elements el = static_cast<Elements>(i);
        elementComposition[el] = composition;
    }
    this->elementComposition = elementComposition;
}

void Alloy::addElement(Elements element, Composition composition){
    this->elementComposition[element] = composition;
}

void Alloy::editComposition(Elements element, QString input, double value){
    if(input == "min"){
        this->elementComposition[element].updateMin(value);
    }
    if(input == "max"){
        this->elementComposition[element].updateMax(value);
    }
    if(input == "spec"){
        this->elementComposition[element].updateSpec(value);
    }
}

void Alloy::printAlloy(){
    qDebug() << "ALLOY NAME" << this->name;
    qDebug() << "ALLOY CLASS" << enumOp.alloyClassToString(this->alloyClass);
    qDebug() << "COMPOSITION";
    for(int i = MAGNESIUM ; i <= CARBON ; i++) {
        Elements el = static_cast<Elements>(i);
        qDebug() << "Element" << this->enumOp.elementToString(el);
        this->elementComposition[el].print();
    }
}

bool Alloy::verifyAlloy(){
    for(int i = MAGNESIUM ; i <= CARBON ; i++){
        Elements el = static_cast<Elements>(i);
        double min = this->elementComposition[el].getMin();
        double max = this->elementComposition[el].getMax();
        double spec = this->elementComposition[el].getSpec();

        if(min == -1 and max == -1 and spec == -1) continue;
        if(min == -1 or max == -1 or spec == -1) return false;
    }

    return true;
}
