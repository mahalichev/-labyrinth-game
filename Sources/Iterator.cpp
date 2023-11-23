#include "../Headers/Iterator.h"

Iterator::Iterator(Cell *current): current_(current), first_(Field::GetInstance()->First()), last_(Field::GetInstance()->Last()){}

Iterator &Iterator::operator++(){
    if (*this != last_){
        if (this->current_->GetX() != Field::GetInstance()->GetWidth() - 1){
            this->current_ = Field::GetInstance()->CellInfo(this->current_->GetY(), this->current_->GetX()+1);
        } else {
            this->current_ = Field::GetInstance()->CellInfo(this->current_->GetY()+1, 0);
        }
	}
	return *this;
}

Iterator &Iterator::operator++(int){
    if (*this != last_){
        if (this->current_->GetX() != Field::GetInstance()->GetWidth() - 1){
            this->current_ = Field::GetInstance()->CellInfo(this->current_->GetY(), this->current_->GetX()+1);
        } else {
            this->current_ = Field::GetInstance()->CellInfo(this->current_->GetY()+1, 0);
        }
	}
	return *this;
}

Iterator &Iterator::operator--(){
    if (*this != first_){
        if (this->current_->GetX() != 0){
            this->current_ = Field::GetInstance()->CellInfo(this->current_->GetY(), this->current_->GetX()-1);
        } else {
            this->current_ = Field::GetInstance()->CellInfo(this->current_->GetY()-1, Field::GetInstance()->GetWidth()-1);
        }
    }
    return *this;
}

Iterator &Iterator::operator--(int){
    if (*this != first_){
        if (this->current_->GetX() != 0){
            this->current_ = Field::GetInstance()->CellInfo(this->current_->GetY(), this->current_->GetX()-1);
        } else {
            this->current_ = Field::GetInstance()->CellInfo(this->current_->GetY()-1, Field::GetInstance()->GetWidth()-1);
        }
    }
    return *this;
}

bool Iterator::operator==(const Iterator &other){
    return (this->current_->GetX() == other.current_->GetX())
			&& (this->current_->GetY() == other.current_->GetY());
}

bool Iterator::operator!=(const Iterator &other){
    return !((this->current_->GetX() == other.current_->GetX())
			&& (this->current_->GetY() == other.current_->GetY()));
}

Cell &Iterator::operator*(){
    return *this->current_;
}

Iterator::~Iterator(){}
