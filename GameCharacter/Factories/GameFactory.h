//
// Created by Emanuele Casciaro on 23/09/2019.
//

#ifndef ISANGRY_GAMEFACTORY_H
#define ISANGRY_GAMEFACTORY_H

#include "SFML/Graphics.hpp"
#include "../../GUI/GameEngine.h"

class GameFactory {
public:
    ~GameFactory() = delete;
    static void createEnemy(GameEngine& engine);
    static void createProps(GameEngine& engine);
    static void setBoundaries(float first, float last);

private:
    static float start;
    static float stop;

};


#endif //ISANGRY_GAMEFACTORY_H
