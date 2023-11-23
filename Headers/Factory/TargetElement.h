#ifndef TARGETELEMENT_H
#define TARGETELEMENT_H

#include "Element.h"
#include "../Strategy/TargetStrategy.h"

class TargetElement: public Element {
public:
    void Operation(Player &player) override;
private:
    int target_reached_ = 1;
};

#endif
