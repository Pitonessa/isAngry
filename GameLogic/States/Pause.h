//
// Created by mac on 18/10/19.
//

#ifndef ISANGRY_PAUSE_H
#define ISANGRY_PAUSE_H

#include "Screen.h"
#include "../GameEngine.h"

class Pause : public Screen{
private:
    GameEngine* gameEngine;

public:
    explicit Pause(GameEngine*gameEngine);
    void update() override;

};


#endif //ISANGRY_PAUSE_H
