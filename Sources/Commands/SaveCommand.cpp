#include "../../Headers/Commands/SaveCommand.h"

SaveCommand::SaveCommand(int &width, int &height, PlayerCaretaker *player_caretaker, EnemiesCaretaker *enemies_caretaker): width_(width), height_(height), player_caretaker_(player_caretaker), enemies_caretaker_(enemies_caretaker){
    save_.open("LastGame.save", std::fstream::out);
};

void SaveCommand::Execute(){
    try {
        if (!save_.is_open()){
            throw "Can't open file. Game progress won't be saved.\n";
        }
        Iterator field_iterator = Field::GetInstance(this->width_, this->height_)->First();
        for (; field_iterator != Field::GetInstance()->Last(); field_iterator++){
            save_ << (*field_iterator).GetCondition();
        }
        save_ << '\n';
        save_ << width_ << ' ' << height_ << '\n';
        save_ << Field::GetInstance()->Player()->GetY() << ' ' << Field::GetInstance()->Player()->GetX() << '\n';
        PlayerMemento *memento_player = player_caretaker_->GetMemento();
        EnemiesMemento *memento_enemies = enemies_caretaker_->GetMemento();
        save_ << memento_player->hp_ << ' ' << memento_player->score_ << ' ' << memento_player->target_reached_ << '\n';
        save_ << Field::GetInstance()->GetEnemy(1)->GetY() << ' ' << Field::GetInstance()->GetEnemy(1)->GetX() << '\n';
        save_ << memento_enemies->hp_[0] << ' ' << memento_enemies->buff_[0] << ' ' << memento_enemies->damage_[0] << ' ' << memento_enemies->steal_amount_[0] << '\n';
        save_ << Field::GetInstance()->GetEnemy(2)->GetY() << ' ' << Field::GetInstance()->GetEnemy(2)->GetX() << '\n';
        save_ << memento_enemies->hp_[1] << ' ' << memento_enemies->buff_[1] << ' ' << memento_enemies->damage_[1] << ' ' << memento_enemies->steal_amount_[1] << '\n';
        save_ << Field::GetInstance()->GetEnemy(3)->GetY() << ' ' << Field::GetInstance()->GetEnemy(3)->GetX() << '\n';
        save_ << memento_enemies->hp_[2] << ' ' << memento_enemies->buff_[2] << ' ' << memento_enemies->damage_[2] << ' ' << memento_enemies->steal_amount_[2] << '\n';
    }
    catch (FileExceptions &exception){
        std::cerr << "Error: " << exception.GetType() << '\n';
    }
}

SaveCommand::~SaveCommand(){
    if (save_.is_open()){
        save_.close();
    }
}
