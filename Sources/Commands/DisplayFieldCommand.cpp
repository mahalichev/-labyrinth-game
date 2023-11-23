#include "../../Headers/Commands/DisplayFieldCommand.h"

DisplayFieldCommand::DisplayFieldCommand(Iterator &field_iterator, PlayerLogic &player_logic, int &width): field_iterator_(field_iterator), player_logic_(player_logic), width_(width){};

void DisplayFieldCommand::Execute(){
    if ((*field_iterator_).IsPlayer() && player_logic_.player.GetVisibility()){
        std::cout << 'T';
    } else {
        if ((*field_iterator_).IsEnemy()){
            std::cout << 'V';
        } else
        switch ((*field_iterator_).GetCondition()){
            case 0:
                std::cout << ' ';
                break;
            case 1:
                std::cout << '|';
                break;
            case 3:
                std::cout << '+';
                break;
            case 4:
                std::cout << '-';
                break;
            case 5:
                std::cout << 'o';
                break;
            case 6:
                std::cout << '*';
                break;
            case 7:
                std::cout << ' ';
                break;
            case 8:
                std::cout << 's';
                break;
            case 9:
                std::cout << 'e';
                break;
            default:
                std::cout<<(*field_iterator_).GetCondition();
                break;
        }
    }
    if ((*field_iterator_).GetX() == width_-1){
        std::cout << '\n';
    }
}
