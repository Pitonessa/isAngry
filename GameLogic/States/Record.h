//
// Created by mac on 18/10/19.
//

#ifndef ISANGRY_RECORD_H
#define ISANGRY_RECORD_H

#include "Screen.h"
#include "../GameEngine.h"

class Record: public Screen {
private:
    GameEngine* gameEngine;
public:
    explicit Record(GameEngine*gameEngine);
    void update() override;

};


#endif //ISANGRY_RECORD_H
