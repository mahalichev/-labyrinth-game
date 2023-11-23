#include "../../Headers/Strategy/HPStrategy.h"

void HPStrategy::DoAlgorithm(Player &player, int element){
	player.hp_ += element;
}
