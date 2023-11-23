#ifndef FACADE_H
#define FACADE_H

#include <iostream>
#include <cstdlib>
#include <string>
#include "EnemyLogic.h"
#include "./Commands/RunCommand.h"
#include "./Commands/MoveCommand.h"
#include "./Commands/LoadCommand.h"
#include "./Commands/StartCommand.h"
#include "./Commands/GameLogicCommand.h"
#include "./Commands/DisplayInfoCommand.h"
#include "./Memento/PlayerCaretaker.h"
#include "./Memento/EnemiesCaretaker.h"

class Facade{
public:
    void Start();
    void Run();
    void GameLogic(PlayerIterator &player_iterator);
    void Exit();
    ~Facade();
private:
    int width_;
    int height_;
    bool error_ = false;
    bool is_running_ = 1;
    bool level_passed_ = 0;
    Enemy<int> enemy_[3];
    EnemyLogic enemy_logic_;
    PlayerCaretaker *player_caretaker_;
    EnemiesCaretaker *enemies_caretaker_;
    PlayerLogic player_logic_;
    PlayerObserver *player_observer_;
    Abstraction *abstraction_;
};

#endif
