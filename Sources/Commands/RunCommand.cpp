#include "../../Headers/Commands/RunCommand.h"

RunCommand::RunCommand(PlayerLogic &player_logic, int &width, int &height): player_logic_(player_logic), width_(width), height_(height){};

void RunCommand::Execute(){
    system("clear");
    Iterator field_iterator = Field::GetInstance(this->width_, this->height_)->First();
    for (; field_iterator != Field::GetInstance()->Last(); field_iterator++){
        Command *command = new DisplayFieldCommand(field_iterator, player_logic_, this->width_);
        command->Execute();
        delete command;
    }
    std::cout << '|' << std::endl;
}
