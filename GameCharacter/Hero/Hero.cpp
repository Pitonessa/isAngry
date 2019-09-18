//
// Created by Emanuele Casciaro on 16/09/2019.
//

#include <iostream>
#include "Hero.h"

Hero::Hero(float speed, sf::Texture &texture, sf::Vector2f position) : GameCharacter(speed, texture) {
    c.restart();
    setTextureRect(textureFrame[actualFrame]);
    setPosition(position);
}

void Hero::move(std::vector<sf::Vector2f> directions) {
    sf::Vector2f direction;
    for (auto i : directions) {
        direction += i;
    }
    setPosition(
            getPosition() + direction * GameCharacter::speed
            );
}

void Hero::move(sf::Vector2f direction) {
    setPosition(
            getPosition() + direction * speed
            );
}

void Hero::attack() {

}

void Hero::animate() {
    if(c.getElapsedTime() >= sf::milliseconds(125)){
        c.restart();
        if(actualFrame < textureFrame.size() - 1)
            actualFrame++;
        else
            actualFrame = 0;
        setTextureRect(textureFrame[actualFrame]);
    }
}