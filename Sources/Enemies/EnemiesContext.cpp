#include "../../Headers/Enemies/EnemiesContext.h"

EnemiesContext::EnemiesContext(): state_(nullptr){

}

void EnemiesContext::TransitionTo(State *state){
    if (this->state_ != nullptr){
        delete this->state_;
    }
    this->state_ = state;
    this->state_->SetContext(this);
}

void EnemiesContext::Request(){
    this->state_->Handle();
}

EnemiesContext::~EnemiesContext(){
    delete state_;
}
