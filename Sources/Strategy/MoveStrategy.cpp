#include "../../Headers/Strategy/MoveStrategy.h"

void MoveStrategy::DoAlgorithm(Player &player, int element){
	player.score_ -= element;
}
