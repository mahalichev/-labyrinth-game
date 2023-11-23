#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include "Command.h"
#include "ExitCommand.h"
#include "../PlayerIterator.h"

class MoveCommand: public Command{
public:
    MoveCommand(PlayerIterator &player_iterator, bool &is_running, bool &level_passed, char &directory, int &width, int &height, PlayerCaretaker *player_caretaker, EnemiesCaretaker *enemies_caretaker);
    void Execute() override;
private:
    PlayerIterator &player_iterator_;
    bool &is_running_;
    bool &level_passed_;
    char &directory_;
    int &width_;
    int &height_;
    PlayerCaretaker *player_caretaker_;
    EnemiesCaretaker *enemies_caretaker_;
};

#endif
