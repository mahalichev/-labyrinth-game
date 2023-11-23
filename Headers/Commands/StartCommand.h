#ifndef STARTCOMMAND_H
#define STARTCOMMAND_H

#include "Command.h"
#include <iostream>

class StartCommand: public Command{
public:
    StartCommand(int &width, int &height);
    void Execute() override;
private:
    int &width_;
    int &height_;
};

#endif
