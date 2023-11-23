#ifndef CREATOR_H
#define CREATOR_H

#include "Element.h"

class Creator{
public:
    virtual ~Creator(){};
    virtual Element* FactoryMethod() = 0;
    void ExecuteElement(Player &player);
};

#endif
