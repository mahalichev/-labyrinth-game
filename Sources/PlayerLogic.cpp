#include "../Headers/PlayerLogic.h"

void PlayerLogic::operator+(Creator &creator){
    creator.ExecuteElement(player);
}

void PlayerLogic::Update(int x, int y){
    player.SetX(x);
    player.SetY(y);
}

void PlayerLogic::operator-(Enemy<int> &enemy){
    PlayerHandle *player_turn = new PlayerHandle(player, enemy);
    context.TransitionTo(player_turn);
    context.Request();
    EnemyHandle *enemy_turn = new EnemyHandle(player, enemy);
    context.TransitionTo(enemy_turn);
    context.Request();
}

PlayerMemento *PlayerLogic::Save(){
    PlayerMemento* memento = new PlayerMemento(&(this->player));
    return memento;
}

void PlayerLogic::Restore(PlayerMemento *memento){
    player.hp_ = memento->hp_;
    player.score_ = memento->score_;
    player.target_reached_ = memento->target_reached_;
}
