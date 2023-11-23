#include "../../Headers/Enemies/BuffsHandle.h"

BuffsHandle::BuffsHandle(Player &player, Enemy<int> &enemy): enemy_(enemy), player_(player){};

void BuffsHandle::Handle(){
    int random_number = rand() % 100;
    if (random_number < 7){
        enemy_.SetBuffId(1);
    }
    if (random_number >= 85){
        enemy_.SetBuffId(2);
    }
    if ((random_number >= 7) && (random_number < 85)){
        enemy_.SetBuffId(0);
    }
    if ((enemy_.GetBuffId() == 1) && (abs(enemy_.GetX()-player_.GetX()) <= 2) && (abs(enemy_.GetY()-player_.GetY()) <= 2)){
        player_.SetVisibility(false);
    } else {
        player_.SetVisibility(true);
    }
}
