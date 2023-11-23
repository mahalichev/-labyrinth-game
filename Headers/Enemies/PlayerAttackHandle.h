#ifndef PLAYERATTACKHANDLE_H
#define PLAYERATTACKHANDLE_H

#include "State.h"
#include "Enemy.hpp"
#include "../Player.h"

class PlayerAttackHandle: public State{
public:
    PlayerAttackHandle(Player &player, Enemy<int> &enemy);
    void Handle() override;
private:
    Player &player_;
    Enemy<int> &enemy_;
};

#endif
