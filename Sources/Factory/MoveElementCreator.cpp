#include "../../Headers/Factory/MoveElementCreator.h"

Element *MoveElementCreator::FactoryMethod(){
    return new MoveElement();
}
