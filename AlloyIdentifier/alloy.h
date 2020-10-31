#ifndef ALLOY_H
#define ALLOY_H

#import <QString>
#import <map>
#import "composition.h"
#import "enumoperator.h"

using namespace std;

class Alloy
{
private:
    QString name;
    AlloyClass alloyClass;
    map <Elements, Composition> elementComposition;
    EnumOperator enumOp;

public:
    Alloy(QString name, AlloyClass alloyClass);
    QString getName();
    AlloyClass getAlloyClass();
    Composition getCompositionOfElement(Elements el);
    void addElement(Elements element, Composition composition);
    void editComposition(Elements element, QString input, double value);
    void printAlloy();
    bool verifyAlloy();
    void fillValuesAlloy();
    bool isComparable(Alloy alloy);

    bool operator<(const Alloy& a1) const{
        return (this->name.size() < a1.name.size());
    }
};

#endif // ALLOY_H
