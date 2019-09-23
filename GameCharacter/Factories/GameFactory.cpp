//
// Created by Emanuele Casciaro on 23/09/2019.
//

#include "GameFactory.h"
#include "../Brawler/Brawler.h"

float GameFactory::start = 0;
float GameFactory::stop = 0;

void GameFactory::setBoundaries(float first, float last) {
    GameFactory::start = start;
    GameFactory::stop = stop;
}

void GameFactory::createEnemy(GameEngine &engine) {
    GameCharacter* enemy;
    float sf = static_cast<float>((rand() % 3) + 2) / 10;
    float sped = static_cast<float>((rand() % 8) + 2) / 10;
    enemy = new Brawler(5, *(engine.brawlerTexture), sf::Vector2f(300, 300));
    enemy->scale(sf, sf);
    engine.addEnemy(*enemy);
}