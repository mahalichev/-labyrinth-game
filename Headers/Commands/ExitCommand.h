#ifndef EXITCOMMAND_H
#define EXITCOMMAND_H

#include "Command.h"
#include "SaveCommand.h"
#include "../Memento/PlayerCaretaker.h"
#include "../Memento/EnemiesCaretaker.h"
#include <iostream>

class ExitCommand: public Command{
public:
    ExitCommand(bool &is_running, bool &level_passed, int condition, int &width, int &height, PlayerCaretaker *player_caretaker, EnemiesCaretaker *enemies_caretaker);
    void Execute() override;
private:
     bool &is_running_;
     bool &level_passed_;
     int condition_;
     int &width_;
     int &height_;
     PlayerCaretaker *player_caretaker_;
     EnemiesCaretaker *enemies_caretaker_;
};

#endif
