#ifndef PLAYEROBSERVER_H
#define PLAYEROBSERVER_H

#include <iostream>
#include <fstream>
#include "../Player.h"
#include "IObserver.h"

class PlayerObserver: public IObserver{
public:
    PlayerObserver();
    void Update(ISubject* element) override;
    virtual ~PlayerObserver();
private:
    std::fstream player_logs_;
};

#endif
