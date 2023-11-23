#include "../../Headers/Factory/AddScoreElementCreator.h"

Element *AddScoreElementCreator::FactoryMethod(){
    return new AddScoreElement();
}
