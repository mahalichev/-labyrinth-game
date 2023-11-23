#ifndef ENEMIESMEMENTO_H
#define ENEMIESMEMENTO_H

#include "Memento.h"
#include "../Enemies/Enemy.hpp"
#include <vector>

class EnemiesMemento: public Memento{
public:
    friend class EnemyLogic;
    friend class LoadCommand;
    friend class SaveCommand;
    EnemiesMemento(Enemy<int> *enemy);
    ~EnemiesMemento();
private:
    int *hp_;
    int *buff_;
    int *damage_;
    int *steal_amount_;
};

#endif
