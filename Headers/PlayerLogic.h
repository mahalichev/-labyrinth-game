#ifndef PLAYERLOGIC_H
#define PLAYERLOGIC_H

#include "./Enemies/EnemiesContext.h"
#include "./Enemies/PlayerHandle.h"
#include "./Enemies/EnemyHandle.h"
#include "./Enemies/Enemy.hpp"
#include "./Factory/Creator.h"
#include "./Logs/PlayerObserver.h"
#include "./Memento/PlayerMemento.h"

class PlayerLogic{
public:
    Player player;
    void operator+(Creator &creator);
    void Update(int x, int y);
    void operator-(Enemy<int> &enemy);
    PlayerMemento *Save();
    void Restore(PlayerMemento *memento);
private:
    EnemiesContext context;
};

#endif
