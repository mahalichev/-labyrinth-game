#include "../../Headers/Factory/DamageElement.h"

void DamageElement::Operation(Player &player){
    StrategyContext *context = new StrategyContext(new DamageStrategy);
	context->DoLogic(player, this->damage_);
	delete context;
}
