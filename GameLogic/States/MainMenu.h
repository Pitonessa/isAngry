//
// Created by mac on 18/10/19.
//

#ifndef ISANGRY_MAINMENU_H
#define ISANGRY_MAINMENU_H


#include "Screen.h"
#include "../GameEngine.h"


class MainMenu : public Screen {
private:
    GameEngine* gameEngine;
public:
    explicit MainMenu(GameEngine* gameEngine);
    void update() override;
    void handleinput(sf::Keyboard::Key key) override;




};




#endif //ISANGRY_MAINMENU_H
