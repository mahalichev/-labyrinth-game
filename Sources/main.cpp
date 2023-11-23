#include "../Headers/Facade.h"

int main(){
    Facade *game = new Facade;
    game->Start();
    delete game;
	return 0;
}
