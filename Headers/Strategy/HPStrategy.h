#ifndef HPSTRATEGY_H
#define HPSTRATEGY_H

#include "Strategy.h"

class HPStrategy: public Strategy{
public:
    void DoAlgorithm(Player &player, int element) override;
};

#endif
