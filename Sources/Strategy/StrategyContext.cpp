#include "../../Headers/Strategy/StrategyContext.h"

StrategyContext::StrategyContext(Strategy *strategy): strategy_(strategy){}

void StrategyContext::SetStrategy(Strategy *strategy){
    delete this->strategy_;
    this->strategy_ = strategy;
}

void StrategyContext::DoLogic(Player &player, int element){
    this->strategy_->DoAlgorithm(player, element);
}

StrategyContext::~StrategyContext(){
    delete this->strategy_;
}
