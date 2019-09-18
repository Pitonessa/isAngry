//
// Created by Emanuele Casciaro on 18/09/2019.
//

#ifndef ISANGRY_GAMEENGINE_H
#define ISANGRY_GAMEENGINE_H


#include "SFML/Graphics.hpp"
#include "../GameObjects/Bullet/Bullet.h"

class GameEngine {


private:
    sf::RenderWindow* gameWindow;
    std::vector<Bullet*> bullets;
    //td::vector<GameObjects*>

};


#endif //ISANGRY_GAMEENGINE_H
