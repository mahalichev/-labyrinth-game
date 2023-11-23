#ifndef DISPLAYFIELDCOMMAND_H
#define DISPLAYFIELDCOMMAND_H

#include "Command.h"
#include "../PlayerLogic.h"
#include "../Iterator.h"

class DisplayFieldCommand: public Command{
public:
    DisplayFieldCommand(Iterator &field_iterator, PlayerLogic &player_logic, int &width);
    void Execute() override;
private:
    Iterator &field_iterator_;
    PlayerLogic &player_logic_;
    int &width_;
};

#endif
