#ifndef PLAYERMEMENTO_H
#define PLAYERMEMENTO_H

#include "Memento.h"
#include "../Player.h"

class PlayerMemento: public Memento{
public:
    friend class PlayerLogic;
    friend class LoadCommand;
    friend class SaveCommand;
    PlayerMemento(Player *player);
private:
    int hp_;
    int score_;
    bool target_reached_;
};

#endif
