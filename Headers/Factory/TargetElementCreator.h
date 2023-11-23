#ifndef TARGETELEMENTCREATOR_H
#define TARGETELEMENTCREATOR_H

#include "Creator.h"
#include "TargetElement.h"

class TargetElementCreator: public Creator{
public:
	Element *FactoryMethod() override;
};

#endif
