#ifndef HPELEMENT_H
#define HPELEMENT_H

#include "Element.h"
#include "../Strategy/HPStrategy.h"

class HPElement: public Element {
public:
    void Operation(Player &player) override;
private:
    int hp_ = 1;
};

#endif
