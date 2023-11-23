#include "../../Headers/Factory/Creator.h"

void Creator::ExecuteElement(Player &player){
    Element *element = this->FactoryMethod();
	element->Operation(player);
	delete element;
}
