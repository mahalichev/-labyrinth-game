#ifndef MOVEELEMENTCREATOR_H
#define MOVEELEMENTCREATOR_H

#include "Creator.h"
#include "MoveElement.h"

class MoveElementCreator: public Creator{
public:
	Element *FactoryMethod() override;
};

#endif
