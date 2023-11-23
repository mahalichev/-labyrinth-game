#include "../../Headers/Strategy/TargetStrategy.h"

void TargetStrategy::DoAlgorithm(Player &player, int element){
	player.target_reached_ = element;
}
