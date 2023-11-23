#ifndef BUFFSHANDLE_H
#define BUFFSHANDLE_H

#include "State.h"
#include "Enemy.hpp"
#include "../Player.h"
#include <cstdlib>

class BuffsHandle: public State{
public:
    BuffsHandle(Player &player, Enemy<int> &enemy);
    void Handle() override;
private:
    Enemy<int> &enemy_;
    Player &player_;
};

#endif
