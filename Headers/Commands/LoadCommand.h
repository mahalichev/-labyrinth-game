#ifndef LOADCOMMAND_H
#define LOADCOMMAND_H

#include "Command.h"
#include "../Iterator.h"
#include "../Field.h"
#include "FileExceptions.h"
#include "../Memento/PlayerCaretaker.h"
#include "../Memento/EnemiesCaretaker.h"
#include <string>
#include <string.h>
#include <sstream>
#include <fstream>
#include <iostream>

class LoadCommand: public Command{
public:
    LoadCommand(int &width, int &height, PlayerCaretaker *player_caretaker, EnemiesCaretaker *enemies_caretaker, PlayerLogic *player_logic, EnemyLogic *enemy_logic, bool &error);
    void Execute() override;
    ~LoadCommand();
private:
    std::fstream load_;
    int &width_;
    int &height_;
    PlayerCaretaker *player_caretaker_;
    EnemiesCaretaker *enemies_caretaker_;
    PlayerLogic *player_logic_;
    EnemyLogic *enemy_logic_;
    bool &error_;
};

#endif
