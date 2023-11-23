#include "../../Headers/Enemies/PlayerHandle.h"

PlayerHandle::PlayerHandle(Player &player, Enemy<int> &enemy): player_(player), enemy_(enemy){};

void PlayerHandle::Handle(){
    if (((enemy_.GetX() - player_.GetX()) == 0) && ((enemy_.GetY() - player_.GetY()) == 0)){
        PlayerAttackHandle *attack_state = new PlayerAttackHandle(player_, enemy_);
        context.TransitionTo(attack_state);
        context.Request();
    }
};
