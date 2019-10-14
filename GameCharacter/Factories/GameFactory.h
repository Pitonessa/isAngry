//
// Created by Emanuele Casciaro on 23/09/2019.
//

#ifndef ISANGRY_GAMEFACTORY_H
#define ISANGRY_GAMEFACTORY_H

#include "SFML/Graphics.hpp"
#include "../../GameLogic/GameEngine.h"

//TODO LOGICA DI CREAZIONE ESTERNA

class GameFactory {
public:
    ~GameFactory() = delete;
    static void createEnemy(GameEngine& engine);
    static void createProps();

};


#endif //ISANGRY_GAMEFACTORY_H
