#include "../Headers/Field.h"

Field *Field::singleton_ = nullptr;

Field::Field(int width, int height): width_(width), height_(height), start_(nullptr), exit_(nullptr){
    this->field_ = new Cell *[this->height_];
    Maze maze(this->width_, this->height_);
    int *map = maze.CreateMaze();
    for (int i = 0; i < this->height_; i++){
        this->field_[i] = new Cell [this->width_];
        for (int j = 0; j < this->width_; j++){
            this->field_[i][j].NewCell(i, j, map[i*this->width_ + j]);
        }
    }
    this->field_[1][2].SetCondition(3);
    this->field_[1][3].SetCondition(4);
    this->field_[2][2].SetCondition(5);
    this->field_[2][1].SetCondition(6);
    this->start_ = &this->field_[1][1];
    this->start_->SetCondition(8);
    SetPlayer(start_);
    this->exit_ = &this->field_[height_-2][width_-2];
    this->exit_->SetCondition(9);
    this->enemy_[0] = &this->field_[0][0];
    this->enemy_[1] = &this->field_[0][0];
    this->enemy_[2] = &this->field_[0][0];
    SetEnemy(1, &this->field_[1][width_-2]);
    SetEnemy(2, &this->field_[height_-2][1]);
    SetEnemy(3, &this->field_[width_-2][width_-2]);
    for (int i = 0; i < this->height_; i++){
        for (int j = 0; j < this->width_; j++){
            this->field_[i][j].SetCreator(this->field_[i][j].GetCondition());
        }
    }
}

Field::~Field(){
    for (int i = 0; i < this->height_; i++){
        delete [] field_[i];
    }
    delete [] field_;
}

bool Field::IsEmpty(){
    return singleton_ == nullptr;
}

void Field::SetPlayer(Cell *cell){
    this->player_ = cell;
    this->player_->SetPlayer(true);
}

Cell *Field::Player(){
    return this->player_;
}

Cell *Field::CellInfo(int y, int x){
    return &this->field_[y][x];
}

int Field::GetWidth(){
    return this->width_;
}

int Field::GetHeight(){
    return this->height_;
}

Cell *Field::First(){
    return &this->field_[0][0];
}

Cell *Field::Last(){
	return &this->field_[height_-1][width_-1];
}

Cell *Field::Start(){
	return this->start_;
}

Cell *Field::Exit(){
	return this->exit_;
}

void Field::SetEnemy(int number, Cell *cell){
    this->enemy_[number - 1]->SetEnemy(false);
    this->enemy_[number - 1] = cell;
    this->enemy_[number - 1]->SetEnemy(true);
}

Cell *Field::GetEnemy(int number){
    return this->enemy_[number - 1];
}

void Field::RemoveEnemy(int number){
    this->enemy_[number - 1] -> SetEnemy(false);
}

Field *Field::GetInstance(int width, int height){
    if (singleton_ == nullptr){
        singleton_ = new Field(width, height);
    }
    return singleton_;
}

void Field::DeleteInstance(){
    delete singleton_;
    singleton_ = nullptr;
}
