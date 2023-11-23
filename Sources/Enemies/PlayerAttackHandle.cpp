#include "../../Headers/Enemies/PlayerAttackHandle.h"

PlayerAttackHandle::PlayerAttackHandle(Player &player, Enemy<int> &enemy): player_(player), enemy_(enemy){};

void PlayerAttackHandle::Handle(){
    enemy_.SetHP(enemy_.GetHP() - player_.DoDamage());
};
