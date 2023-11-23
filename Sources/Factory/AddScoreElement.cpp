#include "../../Headers/Factory/AddScoreElement.h"

void AddScoreElement::Operation(Player &player){
    StrategyContext *context = new StrategyContext(new AddScoreStrategy);
	context->DoLogic(player, this->score_);
	delete context;
}
