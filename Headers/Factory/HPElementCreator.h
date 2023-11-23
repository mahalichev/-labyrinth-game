#ifndef HPELEMENTCREATOR_H
#define HPELEMENTCREATOR_H

#include "Creator.h"
#include "HPElement.h"

class HPElementCreator: public Creator{
public:
	Element *FactoryMethod() override;
};

#endif
