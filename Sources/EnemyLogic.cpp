#include "../Headers/EnemyLogic.h"

EnemiesMemento *EnemyLogic::Save(){
    EnemiesMemento* memento = new EnemiesMemento(this->enemy);
    return memento;
}

void EnemyLogic::Restore(EnemiesMemento *memento){
    enemy[0].hp_ = memento->hp_[0];
    enemy[1].hp_ = memento->hp_[1];
    enemy[2].hp_ = memento->hp_[2];
    enemy[0].buff_id_ = memento->buff_[0];
    enemy[1].buff_id_ = memento->buff_[1];
    enemy[2].buff_id_ = memento->buff_[2];
    enemy[0].damage_ = memento->damage_[0];
    enemy[1].damage_ = memento->damage_[1];
    enemy[2].damage_ = memento->damage_[2];
    enemy[0].steal_amount_ = memento->steal_amount_[0];
    enemy[1].steal_amount_ = memento->steal_amount_[1];
    enemy[2].steal_amount_ = memento->steal_amount_[2];
}
