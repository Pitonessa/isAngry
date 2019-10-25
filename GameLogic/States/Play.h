//
// Created by mac on 18/10/19.
//

#ifndef ISANGRY_PLAY_H
#define ISANGRY_PLAY_H

#include "Screen.h"
#include "../GameEngine.h"

class Play: public Screen {
private:
    GameEngine* gameEngine;

public:
    explicit Play(GameEngine* gameEngine);
    void update() override;
    void handleinput(sf::Keyboard::Key key) override;


};
#endif //ISANGRY_PLAY_H
