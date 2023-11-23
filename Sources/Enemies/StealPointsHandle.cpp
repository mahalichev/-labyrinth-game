#include "../../Headers/Enemies/StealPointsHandle.h"

StealPointsHandle::StealPointsHandle(Player &player, Enemy<int> &enemy): player_(player), enemy_(enemy){};

void StealPointsHandle::Handle(){
    if (((enemy_.GetX() - player_.GetX()) == 0) && ((enemy_.GetY() - player_.GetY()) == 0)){
        player_.score_ -= enemy_.DoSteal();
    }
};
