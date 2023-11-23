#ifndef PLAYER_H
#define PLAYER_H

#include "./Logs/ISubject.h"
#include <list>
#include <fstream>

class Player: public ISubject{
public:
    Player();
    ~Player();
    int hp_;
    int score_;
    bool target_reached_;
    friend std::ostream& operator<<(std::ostream &output, Player *element);
    void Attach(Abstraction *abstraction) override;
    void Detach(Abstraction *abstraction) override;
    void Notify() override;
    void SetX(int x);
    void SetY(int y);
    void SetVisibility(bool is_visible);
    int GetX();
    int GetY();
    int DoDamage();
    bool GetVisibility();
private:
    std::list<Abstraction*> list_observer_;
    int x_;
    int y_;
    int damage_;
    bool is_visible_;
};

#endif
