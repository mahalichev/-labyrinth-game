#ifndef ENEMIESCARETAKER_H
#define ENEMIESCARETAKER_H

#include "Caretaker.h"
#include "EnemiesMemento.h"
#include "../EnemyLogic.h"

class EnemiesCaretaker: public Caretaker{
public:
    EnemiesCaretaker(EnemyLogic *enemy_logic);
    void Backup() override;
    void Undo() override;
    void SetMemento(EnemiesMemento *memento);
    EnemiesMemento *GetMemento();
private:
    EnemyLogic *enemy_logic_;
    std::vector<EnemiesMemento *> mementos;
};

#endif
