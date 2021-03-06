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

QString Alloy::getName(){
    return this->name;
}

AlloyClass Alloy::getAlloyClass(){
    return this->alloyClass;
}

Composition Alloy::getCompositionOfElement(Elements el){
    return this->elementComposition[el];
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
        if(min > max) return false;
        if(spec > max or spec < min) return false;
    }

    return true;
}

void Alloy::fillValuesAlloy(){
    for(int i = MAGNESIUM ; i <= CARBON ; i++){
        Elements el = static_cast<Elements>(i);
        double min = this->elementComposition[el].getMin();
        double max = this->elementComposition[el].getMax();
        double spec = this->elementComposition[el].getSpec();

        if(min == -1 and max != -1){
            this->elementComposition[el].updateMin(0);
        } else if (min != -1 and max == -1) {
            this->elementComposition[el].updateMax(100);
        }

        if(spec == -1){
            double newValue = (this->elementComposition[el].getMin() + this->elementComposition[el].getMax())/2.0;
            this->elementComposition[el].updateSpec(newValue);
        }
    }

    return;
}

bool Alloy::isComparable(Alloy alloy){
    if(this->alloyClass != alloy.getAlloyClass() and alloy.getAlloyClass() != ANY) return false;

    for(int i = MAGNESIUM ; i <= CARBON ; i++){
        Elements el = static_cast<Elements>(i);
        if(this->elementComposition[el].getSpec()*alloy.getCompositionOfElement(el).getSpec() < 0) return false;
        if(this->elementComposition[el].getMin() - 0.25 > alloy.getCompositionOfElement(el).getSpec()) return false;
        if(this->elementComposition[el].getMax() + 0.25 < alloy.getCompositionOfElement(el).getSpec()) return false;
    }

    return true;
}
