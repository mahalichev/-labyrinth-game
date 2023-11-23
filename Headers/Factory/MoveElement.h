#ifndef MOVEELEMENT_H
#define HPELEMENT_H

#include "Element.h"
#include "../Strategy/MoveStrategy.h"

class MoveElement: public Element {
public:
    void Operation(Player &player) override;
private:
    int move_cost_ = 1;
};

#endif
