#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <time.h>
#include <ctime>
#include <string>

class ISubject;

class IObserver{
public:
    virtual void Update(ISubject *isubject) = 0;
};

#endif
