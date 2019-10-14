//
// Created by Emanuele Casciaro on 09/10/2019.
//

#include "Boss.h"

sf::Texture* Boss::bossTexture = nullptr;

Boss::Boss(float speed, sf::Vector2f position) : GameCharacter(speed, *bossTexture), Archer(speed, position), Brawler(speed, position), Watcher(speed, position) {
    setTextureRect(sf::IntRect(0, 0, 889, 632));
}

bool Boss::loadTexture() {
    bossTexture = new sf::Texture;
    //return bossTexture->loadFromFile("../Res/spritesheet-2.png");
    return true;
}

bool Boss::attack() {
    return true;
}

Bullet* Boss::action(GameCharacter &hero) {
    sf::Vector2f direction(
            hero.getPosition().x - getPosition().x,
            0
    );
    GameCharacter::move(direction);
    return nullptr;
}

void Boss::animate() {
    if(actualFrame >= 6)
        actualFrame = 0;
    else actualFrame++;
    setTextureRect(sf::IntRect(889 * actualFrame, 632 * revert, 889, 632));
}