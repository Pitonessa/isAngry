//
// Created by mac on 18/09/19.
//

#include <iostream>
#include "Brawler.h"

sf::Texture* Brawler::brawlerTexture = nullptr;

Brawler::Brawler(float speed, sf::Vector2f position) : GameCharacter(speed, *Brawler::brawlerTexture) {
    setPosition(position);
    setTextureRect(textureFrame[actualFrame]);
    setPosition(position);
    clock.restart();
}
bool Brawler::attack() {
    return true;
}

void Brawler::move(const GameCharacter &hero) {

    sf::Vector2f distance = hero.getPosition() - getPosition();
    float mag = distance.x * distance.x + distance.y * distance.y;
    if (mag >= 50) {
        distance = distance / sqrt(mag);
        Sprite::move(distance * speedX);
    }
}

void Brawler::animate(){
    if (clock.getElapsedTime()>=sf::milliseconds(1000/6)){
        if(actualFrame < textureFrame.size() - 1)
            actualFrame++;
        else
            actualFrame = 0;
        setTextureRect(textureFrame[actualFrame]);
        clock.restart();

    }

}

Bullet* Brawler::action(GameCharacter& hero) {
    move(hero);
    return nullptr;
}

bool Brawler::loadTexture() {
    brawlerTexture = new sf::Texture;
    return brawlerTexture->loadFromFile("../Res/lanter_walk_original.png");
}
