#ifndef STRATEGY_H
#define STRATEGY_H

#include <iostream>
#include "../Player.h"

class Strategy{
public:
    virtual ~Strategy() {}
    virtual void DoAlgorithm(Player &player, int element) = 0;
};

#endif
