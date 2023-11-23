#ifndef ADDSCORESTRATEGY_H
#define ADDSCORESTRATEGY_H

#include "Strategy.h"

class AddScoreStrategy: public Strategy{
public:
    void DoAlgorithm(Player &player, int element) override;
};

#endif
