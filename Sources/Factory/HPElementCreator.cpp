#include "../../Headers/Factory/HPElementCreator.h"

Element *HPElementCreator::FactoryMethod(){
    return new HPElement();
}
