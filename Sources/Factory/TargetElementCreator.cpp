#include "../../Headers/Factory/TargetElementCreator.h"

Element *TargetElementCreator::FactoryMethod(){
    return new TargetElement();
}
