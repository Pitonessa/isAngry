//
// Created by Emanuele Casciaro on 23/09/2019.
//

#include "GameFactory.h"
#include "../Brawler/Brawler.h"
#include "../Archer/Archer.h"
#include "../Watcher/Watcher.h"
#include "../Boss/Boss.h"



 GameCharacter* GameFactory::createEnemy(GameFactory::enemytype type) {
    float speed = static_cast<float>(rand()%41+10)/10;
    GameCharacter* result= nullptr;

    switch(type){

        case BRAWLER:

            result = new Brawler(speed, sf::Vector2f());
            result->scale(1,1);

            break;
        case WATCHER:

            result = new Watcher(speed, sf::Vector2f());
            result->scale(1,1);

            break;
        case ARCHER:

            result = new Archer(speed, sf::Vector2f());
            result->scale(1,1);

            break;
        case BOSS:

            result = new Boss(speed,sf::Vector2f());
            result->scale(1,1);

            break;
        default:
            std::cerr<<"Caso non definito";
            break;
    }
}