#include "../../Headers/Memento/PlayerMemento.h"

PlayerMemento::PlayerMemento(Player *player){
    hp_ = player->hp_;
    score_ = player->score_;
    target_reached_ = player->target_reached_;
}
