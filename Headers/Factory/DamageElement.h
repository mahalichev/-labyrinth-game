#ifndef DAMAGEELEMENT_H
#define DAMAGEELEMENT_H

#include "Element.h"
#include "../Strategy/DamageStrategy.h"

class DamageElement: public Element {
public:
    void Operation(Player &player) override;
private:
    int damage_ = 2;
};

#endif
