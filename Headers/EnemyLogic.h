#ifndef ENEMYLOGIC_H
#define ENEMYLOGIC_H

#include "./Enemies/Enemy.hpp"
#include "./Memento/EnemiesMemento.h"

class EnemyLogic{
public:
    Enemy<int> *enemy;
    EnemiesMemento *Save();
    void Restore(EnemiesMemento *memento);
};

#endif
