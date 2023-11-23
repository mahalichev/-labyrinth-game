#ifndef GAMELOGICCOMMAND_H
#define GAMELOGICCOMMAND_H

#include "Command.h"
#include "ExitCommand.h"
#include "../Enemies/Enemy.hpp"
#include "../PlayerLogic.h"
#include "../PlayerIterator.h"

class GameLogicCommand: public Command{
public:
    GameLogicCommand(PlayerLogic &player_logic, Enemy<int> *enemy, PlayerIterator &player_iterator, bool &is_running, bool &level_passed, int &width, int &height, PlayerCaretaker *player_caretaker, EnemiesCaretaker *enemies_caretaker);
    void Execute() override;
private:
    PlayerLogic &player_logic_;
    Enemy<int> *enemy_;
    PlayerIterator &player_iterator_;
    bool &is_running_;
    bool &level_passed_;
    int &width_;
    int &height_;
    PlayerCaretaker *player_caretaker_;
    EnemiesCaretaker *enemies_caretaker_;
};

#endif
