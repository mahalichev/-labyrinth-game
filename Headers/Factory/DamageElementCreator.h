#ifndef DAMAGEELEMENTCREATOR_H
#define DAMAGEELEMENTCREATOR_H

#include "Creator.h"
#include "DamageElement.h"

class DamageElementCreator: public Creator{
public:
	Element *FactoryMethod() override;
};

#endif
