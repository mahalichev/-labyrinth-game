#include "../Headers/Player.h"

Player::Player(){
    this->hp_ = 10;
    this->score_ = 100;
    this->target_reached_ = false;
    this->is_visible_ = true;
    this->damage_ = 3;
}

Player::~Player(){}

void Player::SetX(int x){
    x_ = x;
};

void Player::SetY(int y){
    y_ = y;
};

int Player::GetX(){
    return x_;
};

int Player::GetY(){
    return y_;
};

int Player::DoDamage(){
    return damage_;
}

void Player::SetVisibility(bool is_visible){
    is_visible_ = is_visible;
}

bool Player::GetVisibility(){
    return is_visible_;
}

std::ostream& operator<<(std::ostream &output, Player *element){
    output << "Player HP - " << element->hp_ << "\n";
    output << "Player Score - " << element->score_ << "\n";
    output << "Player Target Reached - " << element->target_reached_ << "\n\n";
    return output;
}

void Player::Attach(Abstraction *abstraction){
    this->list_observer_.push_back(abstraction);
}

void Player::Detach(Abstraction *abstraction){
    this->list_observer_.remove(abstraction);
}

void Player::Notify(){
    std::list<Abstraction*>::iterator i = list_observer_.begin();
    while(i != list_observer_.end()){
        (*i)->Operation(this);
        ++i;
    }
}
