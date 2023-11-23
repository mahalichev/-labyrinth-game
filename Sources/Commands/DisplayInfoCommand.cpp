#include "../../Headers/Commands/DisplayInfoCommand.h"

DisplayInfoCommand::DisplayInfoCommand(PlayerLogic &player_logic, Enemy<int> *enemy): player_logic_(player_logic), enemy_(enemy){};

void DisplayInfoCommand::Execute(){
    std::cout << "ENEMIES HP: " << enemy_[0].GetHP() << ' ' << enemy_[1].GetHP() << ' ' << enemy_[2].GetHP() << ' ' << std::endl;
    std::cout << "ENEMIES BUFFS: " << enemy_[0].GetBuffId() << ' ' << enemy_[1].GetBuffId() << ' ' << enemy_[2].GetBuffId() << ' ' << std::endl;
    std::cout << "HP: " << player_logic_.player.hp_ << std::endl;
    std::cout << "SCORE: " << player_logic_.player.score_ << std::endl;
    std::cout << "PLAYER COORDS: " << player_logic_.player.GetX() << ' ' << player_logic_.player.GetY() << std::endl;
    std::cout << "\nEnter to continue..." << std::endl;
}
