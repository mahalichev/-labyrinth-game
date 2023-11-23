#ifndef MOVESTRATEGY_H
#define MOVESTRATEGY_H

#include "Strategy.h"

class MoveStrategy: public Strategy{
public:
    void DoAlgorithm(Player &player, int element) override;
};

#endif
