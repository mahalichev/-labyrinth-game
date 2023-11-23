#ifndef SAVECOMMAND_H
#define SAVECOMMAND_H

#include "Command.h"
#include "../Iterator.h"
#include "FileExceptions.h"
#include "../Memento/PlayerCaretaker.h"
#include "../Memento/EnemiesCaretaker.h"
#include <fstream>
#include <sstream>

class SaveCommand: public Command{
public:
    SaveCommand(int &width, int &height, PlayerCaretaker *player_caretaker, EnemiesCaretaker *enemies_caretaker);
    void Execute() override;
    ~SaveCommand();
private:
    std::fstream save_;
    int &width_;
    int &height_;
    PlayerCaretaker *player_caretaker_;
    EnemiesCaretaker *enemies_caretaker_;
};

#endif
