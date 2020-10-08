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

public:
    Alloy(QString name, AlloyClass alloyClass);
    void addElement(Elements element, Composition composition);
};

#endif // ALLOY_H
