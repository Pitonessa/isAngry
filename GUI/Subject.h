//
// Created by Emanuele Casciaro on 04/10/2019.
//

#ifndef ISANGRY_SUBJECT_H
#define ISANGRY_SUBJECT_H


#include <vector>
#include "Observer.h"

class Subject {

public:
    ~Subject();
    void attachObserver(Observer* o);
    void detachObserver(Observer* o);
    virtual void notify() = 0;

protected:
    std::vector<Observer*> observerList;

};


#endif //ISANGRY_SUBJECT_H
