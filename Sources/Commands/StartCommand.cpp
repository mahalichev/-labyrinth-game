#include "../../Headers/Commands/StartCommand.h"

StartCommand::StartCommand(int &width, int &height): width_(width), height_(height){};

void StartCommand::Execute(){
    do{
        std::cout << "Width = ";
        std::cin >> this->width_;
        std::cout << "Height = ";
        std::cin >> this->height_;
    } while ((this->width_ < 5 || this->width_ > 210) || (this->height_ < 5 || this->height_ > 50) || !(this->width_%2) || !(this->height_%2));
}
