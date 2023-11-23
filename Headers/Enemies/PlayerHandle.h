#ifndef PLAYERHANDLE_H
#define PLAYERHANDLE_H

#include "State.h"
#include "EnemiesContext.h"
#include "Enemy.hpp"
#include "../Player.h"
#include "PlayerAttackHandle.h"

class PlayerHandle: public State{
public:
    PlayerHandle(Player &player, Enemy<int> &enemy);
    void Handle() override;
private:
    EnemiesContext context;
    Player &player_;
    Enemy<int> &enemy_;
};

#endif
