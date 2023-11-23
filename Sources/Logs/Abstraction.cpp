#include "../../Headers/Logs/Abstraction.h"

Abstraction::Abstraction(IObserver *iObserver): iObserver_(iObserver){};

void Abstraction::Operation(ISubject *element) const{
    this->iObserver_->Update(element);
}
