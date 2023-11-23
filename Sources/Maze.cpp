#include "../Headers/Maze.h"

Maze::Maze(int width, int height): width_(width), height_(height){};

int *Maze::CreateMaze(){
    this->grid_ = new int[this->width_ * this->height_];
    srand(time(0));
    IdentifyGrid();
    Visit(1,1);
    return this->grid_;
}

void Maze::IdentifyGrid(){
    for (int i = 0; i < this->width_ * this->height_; i++){
        this->grid_[i] = 1;
    }
}

int Maze::XYToIndex(int x, int y){
    return y * this->width_ + x;
}

bool Maze::IsInBounds(int x, int y){
    if (x < 0 || x >= this->width_) return false;
    if (y < 0 || y >= this->height_) return false;
    return true;
}

void Maze::Visit(int x, int y){
    this->grid_[XYToIndex(x,y)] = 0;
    int dirs[4];
    dirs[0] = NORTH;
    dirs[1] = EAST;
    dirs[2] = SOUTH;
    dirs[3] = WEST;
    for (int i = 0; i < 4; i++){
        int r = rand() & 3;
        int temp = dirs[r];
        dirs[r] = dirs[i];
        dirs[i] = temp;
    }
    for (int i = 0; i < 4; i++){
        int dx = 0 , dy = 0;
        switch (dirs[i]){
            case NORTH:
                dy = -1;
                break;
            case SOUTH:
                dy = 1;
                break;
            case EAST:
                dx = 1;
                break;
            case WEST:
                dx = -1;
                break;
        }
        int x2 = x + (dx<<1);
        int y2 = y + (dy<<1);
        if (IsInBounds(x2,y2)){
            if (this->grid_[XYToIndex(x2,y2)] == 1){
                this->grid_[XYToIndex(x2-dx,y2-dy)] = 0;
                Visit(x2,y2);
            }
        }
    }
}

Maze::~Maze(){
    delete [] this->grid_;
}
