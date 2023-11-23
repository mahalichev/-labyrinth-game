#include "../../Headers/Commands/MoveCommand.h"

MoveCommand::MoveCommand(PlayerIterator &player_iterator, bool &is_running, bool &level_passed, char &directory, int &width, int &height, PlayerCaretaker *player_caretaker, EnemiesCaretaker *enemies_caretaker): player_iterator_(player_iterator), level_passed_(level_passed), is_running_(is_running), directory_(directory), width_(width), height_(height), player_caretaker_(player_caretaker), enemies_caretaker_(enemies_caretaker){};

void MoveCommand::Execute(){
    while (directory_ == '\n'){
        directory_ = std::getchar();
    }
    switch (directory_){
        case 'w':
            player_iterator_--;
            break;
        case 'a':
            --player_iterator_;
            break;
        case 's':
            player_iterator_++;
            break;
        case 'd':
            ++player_iterator_;
            break;
        default:
            if (directory_ == 'q'){
                Command *exit_command = new ExitCommand(is_running_, level_passed_, 3, width_, height_, player_caretaker_, enemies_caretaker_);
                exit_command->Execute();
                delete exit_command;
            }
            break;
    }
}
