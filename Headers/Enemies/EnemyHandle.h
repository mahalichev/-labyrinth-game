#ifndef ENEMYHANDLE_H
#define ENEMYHANDLE_H

#include "State.h"
#include "EnemiesContext.h"
#include "Enemy.hpp"
#include "../Player.h"
#include "BuffsHandle.h"
#include "DamageHandle.h"
#include "MoveHandle.h"
#include "StealPointsHandle.h"

class EnemyHandle: public State{
public:
    EnemyHandle(Player &player, Enemy<int> &enemy);
    void Handle() override;
private:
    EnemiesContext context;
    Player &player_;
    Enemy<int> &enemy_;
};

#endif
