#ifndef ADDSCOREELEMENTCREATOR_H
#define ADDSCOREELEMENTCREATOR_H

#include "Creator.h"
#include "AddScoreElement.h"

class AddScoreElementCreator: public Creator{
public:
	Element *FactoryMethod() override;
};

#endif
