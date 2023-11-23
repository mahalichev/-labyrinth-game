#ifndef ABSTRACTION_H
#define ABSTRACTION_H

#include "IObserver.h"

class Abstraction{
public:
    Abstraction(IObserver *iObserver);
    virtual void Operation(ISubject *element) const;
private:
    IObserver *iObserver_;
};

#endif
