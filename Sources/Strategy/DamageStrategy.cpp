#include "../../Headers/Strategy/DamageStrategy.h"

void DamageStrategy::DoAlgorithm(Player &player, int element){
	player.hp_ -= element;
}
