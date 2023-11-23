#include "../../Headers/Factory/TargetElement.h"

void TargetElement::Operation(Player &player){
    StrategyContext *context = new StrategyContext(new TargetStrategy);
	context->DoLogic(player, this->target_reached_);
	delete context;
}
