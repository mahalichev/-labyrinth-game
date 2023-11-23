#ifndef PLAYERCARETAKER_H
#define PLAYERCARETAKER_H

#include "Caretaker.h"
#include "PlayerMemento.h"
#include "../PlayerLogic.h"

class PlayerCaretaker: public Caretaker{
public:
    PlayerCaretaker(PlayerLogic *player_logic);
    void Backup() override;
    void Undo() override;
    void SetMemento(PlayerMemento *memento);
    PlayerMemento *GetMemento();
private:
    PlayerLogic *player_logic_;
    std::vector<PlayerMemento *> mementos;
};

#endif
