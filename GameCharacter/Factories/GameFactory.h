//
// Created by Emanuele Casciaro on 23/09/2019.
//

#ifndef ISANGRY_GAMEFACTORY_H
#define ISANGRY_GAMEFACTORY_H

#include "SFML/Graphics.hpp"
#include "../GameCharacter.h"
#include <iostream>

//TODO LOGICA DI CREAZIONE ESTERNA

class GameFactory {
public:
    ~GameFactory() = delete;
    static void createProps();
    static enum enemytype {
        BRAWLER,
        WATCHER,
        ARCHER,
        BOSS
    };
 static GameCharacter* createEnemy(enemytype type);
};


#endif //ISANGRY_GAMEFACTORY_H
