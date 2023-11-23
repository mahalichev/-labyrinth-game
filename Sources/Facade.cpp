#include "../Headers/Facade.h"
void Facade::Start(){
    enemy_logic_.enemy = enemy_;
    player_caretaker_ = new PlayerCaretaker(&player_logic_);
    enemies_caretaker_ = new EnemiesCaretaker(&enemy_logic_);
    char choice;
    std::cout << "Do you want to restore previous game? (y - yes) - ";
    std::cin >> choice;
    if (choice == 'y'){
        Command *load_command = new LoadCommand(this->width_, this->height_, player_caretaker_, enemies_caretaker_, &player_logic_, &enemy_logic_, error_);
        load_command->Execute();
        delete load_command;
    }
    if (Field::IsEmpty() || (choice != 'y') || error_){
        Field::GetInstance()->DeleteInstance();
        Command *start_command = new StartCommand(this->width_, this->height_);
        start_command->Execute();
        delete start_command;
    }
    player_observer_ = new PlayerObserver();
    abstraction_ = new Abstraction(player_observer_);
    player_logic_.player.Attach(abstraction_);
    Facade::Run();
}

void Facade::Run(){
    PlayerIterator player_iterator = Field::GetInstance(this->width_, this->height_)->Player();
    player_caretaker_->Backup();
    for (int i = 0; i < 3; i++){
        enemy_[i].SetNumber(i+1);
    }
    while (is_running_ && (!level_passed_)){
        Command *command = new RunCommand(player_logic_, this->width_, this->height_);
        command->Execute();
        delete command;
        Facade::GameLogic(player_iterator);
    }
    player_logic_.player.Detach(abstraction_);
    Field::GetInstance()->DeleteInstance();
}

void Facade::GameLogic(PlayerIterator &player_iterator){
    player_caretaker_->Backup();
    enemies_caretaker_->Backup();
    Command *game_logic_command = new GameLogicCommand(player_logic_, enemy_, player_iterator, is_running_, level_passed_, width_, height_, player_caretaker_, enemies_caretaker_);
    game_logic_command->Execute();
    delete game_logic_command;
    Command *display_info_command = new DisplayInfoCommand(player_logic_, enemy_);
    display_info_command->Execute();
    delete display_info_command;
    char directory = std::getchar();
    Command *move_command = new MoveCommand(player_iterator, is_running_, level_passed_, directory, width_, height_, player_caretaker_, enemies_caretaker_);
    move_command->Execute();
    delete move_command;
}

Facade::~Facade(){
    delete abstraction_;
    delete player_observer_;
    delete player_caretaker_;
    delete enemies_caretaker_;
}
