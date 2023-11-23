#include "../../Headers/Factory/DamageElementCreator.h"

Element *DamageElementCreator::FactoryMethod(){
    return new DamageElement();
}
