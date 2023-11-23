#ifndef ADDSCOREELEMENT_H
#define ADDSCOREELEMENT_H

#include "Element.h"
#include "../Strategy/AddScoreStrategy.h"

class AddScoreElement: public Element {
public:
    void Operation(Player &player) override;
private:
    int score_ = 10;
};

#endif
