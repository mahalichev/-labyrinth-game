#include "../Headers/PlayerIterator.h"

PlayerIterator::PlayerIterator(Cell *current): current_(current), start_(Field::GetInstance()->Start()), exit_(Field::GetInstance()->Exit()){
    cellObserver_ = new CellObserver();
    abstraction_ = new Abstraction(cellObserver_);
    this->current_->Attach(abstraction_);
    this->current_->Notify();
    this->current_->Detach(abstraction_);
}

PlayerIterator &PlayerIterator::operator++(){
    if ((this->current_->GetY() != Field::GetInstance()->GetWidth() - 1) && (Field::GetInstance()->field_[this->current_->GetY()][this->current_->GetX()+1].GetCondition() != 1)){
        this->current_->SetPlayer(false);
        this->current_ = Field::GetInstance()->CellInfo(this->current_->GetY(), this->current_->GetX()+1);
        Field::GetInstance()->SetPlayer(this->current_);
        this->current_->Attach(abstraction_);
        this->current_->Notify();
        this->current_->Detach(abstraction_);
    }
	return *this;
}

PlayerIterator &PlayerIterator::operator++(int){
    if ((this->current_->GetY() != Field::GetInstance()->GetHeight() - 1) && (Field::GetInstance()->field_[this->current_->GetY()+1][this->current_->GetX()].GetCondition() != 1)){
        this->current_->SetPlayer(false);
        this->current_ = Field::GetInstance()->CellInfo(this->current_->GetY()+1, this->current_->GetX());
        Field::GetInstance()->SetPlayer(this->current_);
        this->current_->Attach(abstraction_);
        this->current_->Notify();
        this->current_->Detach(abstraction_);
    }
	return *this;
}

PlayerIterator &PlayerIterator::operator--(){
    if ((this->current_->GetX() != 0) && (Field::GetInstance()->field_[this->current_->GetY()][this->current_->GetX()-1].GetCondition() != 1)){
        this->current_->SetPlayer(false);
        this->current_ = Field::GetInstance()->CellInfo(this->current_->GetY(), this->current_->GetX()-1);
        Field::GetInstance()->SetPlayer(this->current_);
        this->current_->Attach(abstraction_);
        this->current_->Notify();
        this->current_->Detach(abstraction_);
    }
    return *this;
}

PlayerIterator &PlayerIterator::operator--(int){
    if ((this->current_->GetY() != 0) && (Field::GetInstance()->field_[this->current_->GetY()-1][this->current_->GetX()].GetCondition() != 1)){
        this->current_->SetPlayer(false);
        this->current_ = Field::GetInstance()->CellInfo(this->current_->GetY()-1, this->current_->GetX());
        Field::GetInstance()->SetPlayer(this->current_);
        this->current_->Attach(abstraction_);
        this->current_->Notify();
        this->current_->Detach(abstraction_);
    }
    return *this;
}

bool PlayerIterator::operator==(const PlayerIterator &other){
    return (this->current_->GetX() == other.current_->GetX())
			&& (this->current_->GetY() == other.current_->GetY());
}

bool PlayerIterator::operator!=(const PlayerIterator &other){
    return !((this->current_->GetX() == other.current_->GetX())
			&& (this->current_->GetY() == other.current_->GetY()));
}

Cell &PlayerIterator::operator*(){
    return *this->current_;
}

PlayerIterator::~PlayerIterator(){
    delete abstraction_;
    delete cellObserver_;
}
