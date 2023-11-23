#ifndef FIELD_H
#define FIELD_H

#include "Cell.h"
#include "Maze.h"
#include "./Logs/CellObserver.h"

class Field{
public:
    friend class Iterator;
    friend class PlayerIterator;
    friend class MoveHandle;
    friend class LoadCommand;
	Field(Field& other) = delete;
    Field(Field&& other) = delete;
	Field &operator=(const Field&) = delete;
	Field &operator=(const Field&&) = delete;
    static bool IsEmpty();
    int GetWidth();
    int GetHeight();
    Cell *First();
    Cell *Last();
    Cell *Start();
    void SetPlayer(Cell *cell);
    Cell *Player();
    Cell *Exit();
    void SetEnemy(int number, Cell *cell);
    Cell *GetEnemy(int number);
    void RemoveEnemy(int number);
    static Field *GetInstance(int width = 5, int height = 5);
    void DeleteInstance();
private:
    Field(int width, int height);
    ~Field();
    Cell *CellInfo(int y, int x);
    int width_;
    int height_;
    Cell *start_;
    Cell *player_;
    Cell *exit_;
    Cell *enemy_[3];
    Cell **field_;
    static Field *singleton_;
};

#endif
