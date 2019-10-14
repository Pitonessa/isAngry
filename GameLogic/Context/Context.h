//
// Created by Emanuele Casciaro on 11/10/2019.
//

#ifndef ISANGRY_CONTEXT_H
#define ISANGRY_CONTEXT_H

#include "../States/State.h"

class Context {
private:
    State* state;
public:
    Context();
    const State* getState() const;
    void setState(State* newState);
};


#endif //ISANGRY_CONTEXT_H
