#ifndef ELEMENT_H
#define ELEMENT_H

#include "../Strategy/StrategyContext.h"

class Element{
public:
    virtual ~Element() {};
    virtual void Operation(Player &player) = 0;
};

#endif
