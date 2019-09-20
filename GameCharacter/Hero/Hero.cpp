//
// Created by Emanuele Casciaro on 16/09/2019.
//

#include <iostream>
#include <cmath>
#include "Hero.h"

Hero::Hero(float speed, sf::Texture &texture, sf::Vector2f position) : GameCharacter(speed, texture) {
    c.restart();
    setTextureRect(textureFrame[actualFrame]);
    setPosition(position);
    std::cout << position.x << " - " << position.y;
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
    float prod = direction.x * previusDirection;
    if(prod < 0) {
        scale(sf::Vector2f(-1, 1));
        if(direction.x > 0)
            Sprite::move(-getGlobalBounds().width, 0);
        else Sprite::move(getGlobalBounds().width, 0);
    }
    previusDirection = direction.x;
    Transformable::move(direction * speed / sqrt(direction.x * direction.x + direction.y * direction.y));
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

void Hero::action(GameCharacter &player) {

}