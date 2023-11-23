#ifndef MOVEHANDLE_H
#define MOVEHANDLE_H

#include "State.h"
#include "Enemy.hpp"
#include "../Field.h"

class MoveHandle: public State{
public:
    MoveHandle(Enemy<int> &enemy);
    void Handle() override;
private:
    Enemy<int> &enemy_;
};

#endif
