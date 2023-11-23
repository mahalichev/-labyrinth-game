#include "../../Headers/Strategy/AddScoreStrategy.h"

void AddScoreStrategy::DoAlgorithm(Player &player, int element){
	player.score_ += element;
}
