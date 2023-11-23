#ifndef CELL_H
#define CELL_H

#include "./Factory/AddScoreElementCreator.h"
#include "./Factory/DamageElementCreator.h"
#include "./Factory/HPElementCreator.h"
#include "./Factory/MoveElementCreator.h"
#include "./Factory/TargetElementCreator.h"
#include "./Logs/ISubject.h"
#include <list>

class Cell: public ISubject{
public:
    Cell();
    void NewCell(int y, int x, int condition = 0, bool is_player = false);
    int GetX();
    int GetY();
    bool IsPlayer();
    bool IsEnemy();
    void SetPlayer(bool is_player);
    void SetEnemy(bool is_enemy);
    int GetCondition();
    void SetCondition(int condition);
    void SetCreator(int condition);
    Creator *GetCreator();
    void RemoveCreator();
    friend std::ostream& operator<<(std::ostream &output, Cell *element);
    void Attach(Abstraction *abstraction) override;
    void Detach(Abstraction *abstraction) override;
    void Notify() override;
    ~Cell();
private:
    int x_;
    int y_;
    bool is_player_;
    bool is_enemy_;
    int condition_;
    Creator *creator_;
    std::list<Abstraction*> list_observer_;
};

#endif
