#include "../../Headers/Factory/MoveElement.h"

void MoveElement::Operation(Player &player){
    StrategyContext *context = new StrategyContext(new MoveStrategy);
	context->DoLogic(player, this->move_cost_);
	delete context;
}
