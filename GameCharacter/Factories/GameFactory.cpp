//
// Created by Emanuele Casciaro on 23/09/2019.
//

#include "GameFactory.h"
#include "../Brawler/Brawler.h"
#include "../Archer/Archer.h"
#include "../Watcher/Watcher.h"

void GameFactory::createEnemy(GameEngine &engine) {
    int
        start = engine.getWindow().getView().getCenter().x,
        stop = start + engine.getWindow().getSize().y;
    GameCharacter* enemy;
    float sf = static_cast<float>((rand() % 3) + 2) / 10;
    float speed = static_cast<float>((rand() % 8) + 2) / 10;
    int posX = rand() % (stop - start) + start;
    int seed = rand() % 11;
    if(seed < 10) {
        enemy = new Brawler(speed * 2, sf::Vector2f(posX, 1000));
    } else if(seed < 6) {
        enemy = new Archer(speed, sf::Vector2f(300, 1000));
    } else if(seed < 9) {
        enemy = new Watcher(speed, sf::Vector2f(300, 300));
    } else {
        //TODO ADD BOSS
        enemy = new Brawler(speed, sf::Vector2f(300, 300));
    }
    enemy->scale(sf, sf);
    engine.addEnemy(*enemy);
}