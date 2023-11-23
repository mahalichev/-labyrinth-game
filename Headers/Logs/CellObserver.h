#ifndef CELLOBSERVER_H
#define CELLOBSERVER_H

#include <iostream>
#include <fstream>
#include "../Cell.h"
#include "IObserver.h"

class CellObserver: public IObserver{
public:
    CellObserver();
    void Update(ISubject* element) override;
    virtual ~CellObserver();
private:
    std::fstream cell_logs_;
};

#endif
