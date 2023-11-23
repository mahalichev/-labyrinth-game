#ifndef DAMAGEHANDLE_H
#define DAMAGEHANDLE_H

#include "State.h"
#include "Enemy.hpp"
#include "../Player.h"

class DamageHandle: public State{
public:
    DamageHandle(Player &player, Enemy<int> &enemy);
    void Handle() override;
private:
    Player &player_;
    Enemy<int> &enemy_;
};

#endif
