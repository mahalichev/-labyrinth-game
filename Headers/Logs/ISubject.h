#ifndef ISUBJECT_H
#define ISUBJECT_H

#include "Abstraction.h"

class ISubject{
public:
    virtual void Attach(Abstraction *abstraction) = 0;
    virtual void Detach(Abstraction *abstraction) = 0;
    virtual void Notify() = 0;
};

#endif
