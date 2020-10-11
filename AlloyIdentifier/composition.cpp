#include <QDebug>

#include "composition.h"

Composition::Composition(){
    this->min = -1;
    this->max = -1;
    this->spec = -1;
}

Composition::Composition(double min, double max, double spec){
    this->min = min;
    this->max = max;
    this->spec = spec;
}

double Composition::getMin(){
    return this->min;
}

double Composition::getMax(){
    return this->max;
}

double Composition::getSpec(){
    return this->spec;
}

void Composition::updateMin(double min){
    this->min = min;
}

void Composition::updateMax(double max){
    this->max = max;
}

void Composition::updateSpec(double spec){
    this->spec = spec;
}

void Composition::print(){
    qDebug() << "Min" << this->min << "Max" << this->max << "Spec" << this->spec;
}
