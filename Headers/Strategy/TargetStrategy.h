#ifndef TARGETSTRATEGY_H
#define TARGETSTRATEGY_H

#include "Strategy.h"

class TargetStrategy: public Strategy{
public:
    void DoAlgorithm(Player &player, int element) override;
};

#endif
