#include "composition.h"

Composition::Composition(){
    this->min = 0;
    this->max = 0;
    this->spec = 0;
}

Composition::Composition(double min, double max, double spec){
    this->min = min;
    this->max = max;
    this->spec = spec;
}
