#ifndef ENEMIESCONTEXT_H
#define ENEMIESCONTEXT_H

#include "State.h"

class EnemiesContext{
public:
    EnemiesContext();
    void TransitionTo(State *state);
    void Request();
    ~EnemiesContext();
private:
    State *state_;
};

#endif
