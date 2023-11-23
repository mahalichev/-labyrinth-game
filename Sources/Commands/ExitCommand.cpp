#include "../../Headers/Commands/ExitCommand.h"

ExitCommand::ExitCommand(bool &is_running, bool &level_passed, int condition, int &width, int &height, PlayerCaretaker *player_caretaker, EnemiesCaretaker *enemies_caretaker): is_running_(is_running), level_passed_(level_passed), condition_(condition), width_(width), height_(height), player_caretaker_(player_caretaker), enemies_caretaker_(enemies_caretaker){};

void ExitCommand::Execute(){
    switch(condition_){
        case 1:
            level_passed_ = 1;
            std::cout << "Level Passed" << std::endl;
            break;
        case 2:
            is_running_ = 0;
            std::cout << "Game over" << std::endl;
            break;
        case 3:
            is_running_ = 0;
            std::cout << "Do you want to save game? (y - yes) - ";
            char choice;
            std::cin >> choice;
            if (choice == 'y'){
                Command *save_command = new SaveCommand(width_, height_, player_caretaker_, enemies_caretaker_);
                save_command->Execute();
                delete save_command;
            }
            std::cout << "Exiting..." << std::endl;
            break;
        default:
            break;
    }
}
