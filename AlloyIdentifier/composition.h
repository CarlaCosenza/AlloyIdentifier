#ifndef COMPOSITION_H
#define COMPOSITION_H

class Composition
{
private:
    double min;
    double max;
    double spec;

public:
    Composition();
    Composition(double min, double max, double spec);
    double getMin();
    double getMax();
    double getSpec();
    void updateMin(double min);
    void updateMax(double max);
    void updateSpec(double spec);
    void print();
};

#endif // COMPOSITION_H
