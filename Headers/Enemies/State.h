#ifndef STATE_H
#define STATE_H

class EnemiesContext;

class State{
public:
    void SetContext(EnemiesContext *context);
    virtual void Handle() = 0;
    virtual ~State(){};
protected:
    EnemiesContext *context_;
};

#endif
