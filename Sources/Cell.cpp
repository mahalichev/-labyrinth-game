#include "../Headers/Cell.h"

Cell::Cell(): creator_(nullptr){};

void Cell::NewCell(int y, int x, int condition, bool is_player){
    this->x_ = x;
    this->y_ = y;
    this->condition_ = condition;
    this->is_player_ = is_player;
    this->is_enemy_ = 0;
}

int Cell::GetX(){
    return this->x_;
}

int Cell::GetY(){
    return this->y_;
}

bool Cell::IsPlayer(){
    return this->is_player_;
}

void Cell::SetPlayer(bool is_player){
    this->is_player_ = is_player;
}

bool Cell::IsEnemy(){
    return this->is_enemy_;
}

void Cell::SetEnemy(bool is_enemy){
    this->is_enemy_ = is_enemy;
}

int Cell::GetCondition(){
    return this->condition_;
}

void Cell::SetCondition(int condition){
    this->condition_ = condition;
}

void Cell::SetCreator(int condition){
    switch(condition){
        case 0:
            this->creator_ = new MoveElementCreator();
            break;
        case 3:
            this->creator_ = new HPElementCreator();
            break;
        case 4:
            this->creator_ = new DamageElementCreator();
            break;
        case 5:
            this->creator_ = new AddScoreElementCreator();
            break;
        case 6:
            this->creator_ = new TargetElementCreator();
            break;
        default:
            this->creator_ = nullptr;
            break;
    }
}

Creator *Cell::GetCreator(){
    return this->creator_;
}

void Cell::RemoveCreator(){
	delete this->creator_;
	this->creator_ = nullptr;
	this->condition_ = 7;
}

std::ostream& operator<<(std::ostream &output, Cell *element){
    output << "Current Cell Coordinates - " << element->GetX() << ':' << element->GetY() << "\n";
    output << "Current Cell Condition - " << element->GetCondition() << "\n\n";
    return output;
}

void Cell::Attach(Abstraction *abstraction){
    this->list_observer_.push_back(abstraction);
}

void Cell::Detach(Abstraction *abstraction){
    this->list_observer_.remove(abstraction);
}

void Cell::Notify(){
    std::list<Abstraction*>::iterator i = list_observer_.begin();
    while(i != list_observer_.end()){
        (*i)->Operation(this);
        ++i;
    }
}

Cell::~Cell(){
    delete this->creator_;
}
