#ifndef STEALPOINTSHANDLE_H
#define STEALPOINTSHANDLE_H

#include "State.h"
#include "Enemy.hpp"
#include "../Player.h"

class StealPointsHandle: public State{
public:
    StealPointsHandle(Player &player, Enemy<int> &enemy);
    void Handle() override;
private:
    Player &player_;
    Enemy<int> &enemy_;
};

#endif
