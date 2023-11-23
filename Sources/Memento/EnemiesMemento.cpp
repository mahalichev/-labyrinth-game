#include "../../Headers/Memento/EnemiesMemento.h"

EnemiesMemento::EnemiesMemento(Enemy<int> *enemy){
    hp_ = new int[3];
    buff_ = new int[3];
    damage_ = new int[3];
    steal_amount_ = new int[3];
    hp_[0] = enemy[0].hp_;
    hp_[1] = enemy[1].hp_;
    hp_[2] = enemy[2].hp_;
    buff_[0] = enemy[0].buff_id_;
    buff_[1] = enemy[1].buff_id_;
    buff_[2] = enemy[2].buff_id_;
    damage_[0] = enemy[0].damage_;
    damage_[1] = enemy[1].damage_;
    damage_[2] = enemy[2].damage_;
    steal_amount_[0] = enemy[0].steal_amount_;
    steal_amount_[1] = enemy[1].steal_amount_;
    steal_amount_[2] = enemy[2].steal_amount_;
}

EnemiesMemento::~EnemiesMemento(){
    delete[] hp_;
    delete[] buff_;
    delete[] damage_;
    delete[] steal_amount_;
}
