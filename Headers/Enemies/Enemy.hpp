#ifndef ENEMY_H
#define ENEMY_H

#include "../Player.h"

template<typename T>
class Enemy{
public:
    friend class EnemyLogic;
    friend class EnemiesMemento;
    Enemy();
    int GetX();
    int GetY();
    int GetHP();
    int GetNumber();
    int GetBuffId();
    int DoDamage();
    int DoSteal();
    void SetX(int x);
    void SetY(int y);
    void SetHP(int hp);
    void SetNumber(int number);
    void SetBuffId(int buff_id);
private:
    int x_;
    int y_;
    int hp_;
    int number_;
    int buff_id_;
    int damage_;
    int steal_amount_;
};

template <typename T>
Enemy<T>::Enemy(): x_(0), y_(0), number_(0), buff_id_(0), damage_(1), steal_amount_(10), hp_(5){}

template <typename T>
int Enemy<T>::GetX(){
    return x_;
}

template <typename T>
int Enemy<T>::GetY(){
    return y_;
}

template <typename T>
int Enemy<T>::GetHP(){
    return hp_;
}

template <typename T>
int Enemy<T>::GetNumber(){
    return number_;
}

template <typename T>
int Enemy<T>::GetBuffId(){
    return buff_id_;
}

template <typename T>
int Enemy<T>::DoDamage(){
    return damage_;
}

template <typename T>
int Enemy<T>::DoSteal(){
    return steal_amount_;
}

template <typename T>
void Enemy<T>::SetX(int x){
    x_ = x;
}

template <typename T>
void Enemy<T>::SetY(int y){
    y_ = y;
}

template <typename T>
void Enemy<T>::SetHP(int hp){
    hp_ = hp;
}

template <typename T>
void Enemy<T>::SetNumber(int number){
    number_ = number;
}

template <typename T>
void Enemy<T>::SetBuffId(int buff_id){
    buff_id_ = buff_id;
}

#endif
