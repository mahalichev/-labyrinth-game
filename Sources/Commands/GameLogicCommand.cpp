#include "../../Headers/Commands/GameLogicCommand.h"

GameLogicCommand::GameLogicCommand(PlayerLogic &player_logic, Enemy<int> *enemy, PlayerIterator &player_iterator, bool &is_running, bool &level_passed, int &width, int &height, PlayerCaretaker *player_caretaker, EnemiesCaretaker *enemies_caretaker): player_logic_(player_logic), enemy_(enemy), player_iterator_(player_iterator), is_running_(is_running), level_passed_(level_passed), width_(width), height_(height), player_caretaker_(player_caretaker_), enemies_caretaker_(enemies_caretaker){};

void GameLogicCommand::Execute(){
    player_logic_.Update((*player_iterator_).GetX(), (*player_iterator_).GetY());
    for (int i = 0; i < 3; i++){
        player_logic_-enemy_[i];
    }
    if ((*player_iterator_).GetCreator() != nullptr){
        player_logic_ + (*(*player_iterator_).GetCreator());
        (*player_iterator_).RemoveCreator();
    }
    player_logic_.player.Notify();
    if ((player_logic_.player.hp_ <= 0) || (player_logic_.player.score_ < 0)){
        Command *exit_command = new ExitCommand(is_running_, level_passed_, 2, width_, height_, player_caretaker_, enemies_caretaker_);
        exit_command->Execute();
        delete exit_command;
    } else if (((*player_iterator_).GetCondition() == 9) && player_logic_.player.target_reached_){
        Command *exit_command = new ExitCommand(is_running_, level_passed_, 1, width_, height_, player_caretaker_, enemies_caretaker_);
        exit_command->Execute();
        delete exit_command;
    }
}
