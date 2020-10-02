#ifndef COMPOSITION_H
#define COMPOSITION_H

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

class Composition
{
private:
    double min;
    double max;
    double spec;

public:
    Composition();
    Composition(double min, double max, double spec);
};

#endif // COMPOSITION_H
