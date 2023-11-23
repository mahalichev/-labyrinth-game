#ifndef STRATEGYCONTEXT_H
#define STRATEGYCONTEXT_H

#include "Strategy.h"

class StrategyContext{
public:
    StrategyContext(Strategy *strategy = nullptr);
    ~StrategyContext();
    void SetStrategy(Strategy *strategy);
    void DoLogic(Player &player, int element);
private:
    Strategy *strategy_;
};

#endif
