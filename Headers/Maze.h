#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

class Maze{
public:
    Maze(int width, int height);
    int *CreateMaze();
    void IdentifyGrid();
    int XYToIndex(int x, int y);
    bool IsInBounds(int x, int y);
    void Visit(int x, int y);
    ~Maze();
private:
    int width_;
    int height_;
    int *grid_;
};

#endif
