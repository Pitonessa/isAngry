//
// Created by Emanuele Casciaro on 04/10/2019.
//

#ifndef ISANGRY_OBSERVER_H
#define ISANGRY_OBSERVER_H


#include "../GameObjects/GameObject.h"

class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(GameObject* bullet) = 0;
};


#endif //ISANGRY_OBSERVER_H
