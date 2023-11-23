#include "../../Headers/Memento/EnemiesCaretaker.h"

EnemiesCaretaker::EnemiesCaretaker(EnemyLogic *enemy_logic): enemy_logic_(enemy_logic){}

void EnemiesCaretaker::Backup(){
    mementos.push_back(enemy_logic_->Save());
}

void EnemiesCaretaker::Undo(){
    enemy_logic_->Restore(mementos.back());
    mementos.pop_back();
}

void EnemiesCaretaker::SetMemento(EnemiesMemento *memento){
    mementos.push_back(memento);
}

EnemiesMemento *EnemiesCaretaker::GetMemento(){
    return mementos.back();
}
