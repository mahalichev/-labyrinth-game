#include "../../Headers/Factory/HPElement.h"

void HPElement::Operation(Player &player){
    StrategyContext *context = new StrategyContext(new HPStrategy);
	context->DoLogic(player, this->hp_);
	delete context;
}
