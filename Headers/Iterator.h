#ifndef ITERATOR_H
#define ITERATOR_H

#include "Field.h"

class Iterator{
public:
    Iterator(Cell *current);
    Iterator &operator++();
    Iterator &operator++(int);
    Iterator &operator--();
    Iterator &operator--(int);
    bool operator==(const Iterator &other);
    bool operator!=(const Iterator &other);
    Cell &operator*();
    ~Iterator();
private:
    Cell *first_;
    Cell *last_;
    Cell *current_;
};

#endif
