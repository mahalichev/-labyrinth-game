#ifndef PLAYERITERATOR_H
#define PLAYERITERATOR_H

#include "Field.h"

class PlayerIterator{
public:
    PlayerIterator(Cell *current);
    PlayerIterator &operator++();
    PlayerIterator &operator++(int);
    PlayerIterator &operator--();
    PlayerIterator &operator--(int);
    bool operator==(const PlayerIterator &other);
    bool operator!=(const PlayerIterator &other);
    Cell &operator*();
    ~PlayerIterator();
private:
    Cell *start_;
    Cell *exit_;
    Cell *current_;
    CellObserver *cellObserver_;
    Abstraction *abstraction_;
};

#endif
