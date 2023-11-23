#ifndef CARETAKER_H
#define CARETAKER_H

#include <vector>

class Caretaker{
public:
    virtual void Backup() = 0;
    virtual void Undo() = 0;
};

#endif
