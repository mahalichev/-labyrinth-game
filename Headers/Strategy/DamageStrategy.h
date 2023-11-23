#ifndef DAMAGESTRATEGY_H
#define DAMAGESTRATEGY_H

#include "Strategy.h"

class DamageStrategy: public Strategy{
public:
    void DoAlgorithm(Player &player, int element) override;
};

#endif
