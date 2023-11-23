#ifndef RUNCOMMAND_H
#define RUNCOMMAND_H

#include "Command.h"
#include "../Iterator.h"
#include "DisplayFieldCommand.h"

class RunCommand: public Command{
public:
    RunCommand(PlayerLogic &player_logic, int &width, int &height);
    void Execute() override;
private:
    int &width_;
    int &height_;
    PlayerLogic &player_logic_;
};

#endif
