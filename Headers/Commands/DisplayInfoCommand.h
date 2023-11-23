#ifndef DISPLAYINFOCOMMAND_H
#define DISPLAYINFOCOMMAND_H

#include "Command.h"
#include "../PlayerLogic.h"

class DisplayInfoCommand: public Command{
public:
    DisplayInfoCommand(PlayerLogic &player_logic, Enemy<int> *enemy);
    void Execute() override;
private:
    PlayerLogic &player_logic_;
    Enemy<int> *enemy_;
};

#endif
