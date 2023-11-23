#include "../../Headers/Memento/PlayerCaretaker.h"

PlayerCaretaker::PlayerCaretaker(PlayerLogic *player_logic): player_logic_(player_logic){}

void PlayerCaretaker::Backup(){
    mementos.push_back(player_logic_->Save());
}

void PlayerCaretaker::Undo(){
    player_logic_->Restore(mementos.back());
    mementos.pop_back();
}

void PlayerCaretaker::SetMemento(PlayerMemento *memento){
    mementos.push_back(memento);
}

PlayerMemento *PlayerCaretaker::GetMemento(){
    return mementos.back();
}
