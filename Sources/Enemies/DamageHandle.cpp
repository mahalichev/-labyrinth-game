#include "../../Headers/Enemies/DamageHandle.h"

DamageHandle::DamageHandle(Player &player, Enemy<int> &enemy): player_(player), enemy_(enemy){};

void DamageHandle::Handle(){
    if ((abs(enemy_.GetX() - player_.GetX()) <= 1) && (abs(enemy_.GetY() - player_.GetY()) <= 1)){
        player_.hp_ -= enemy_.DoDamage();
    }
};
