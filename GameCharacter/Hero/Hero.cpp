//
// Created by Emanuele Casciaro on 16/09/2019.
//

#include <iostream>
#include <cmath>
#include "Hero.h"

Hero::Hero(float speed, sf::Texture &texture, sf::Vector2f position) : GameCharacter(speed, texture) {
    setTextureRect(sf::IntRect(0, 0, 80, 86));
    setPosition(position);
}
/*
void Hero::move(std::vector<sf::Vector2f> directions) {
    sf::Vector2f direction;
    for (auto i : directions) {
        direction += i;
    }
    setPosition(
            getPosition() + direction * GameCharacter::speedX
            );
}
*/
void Hero::move(sf::Vector2f direction) {
    direction.x < 0 ? revert = 1 : revert = 0;
    float GroundLevel= 1200;
    direction /= sqrt(direction.x * direction.x + direction.y * direction.y);
    GameCharacter::speed += GameCharacter::gravity;
    GameCharacter::speed.x = direction.x * speedX;
    GameCharacter::speed.y += direction.y;
    Transformable::move(speed);


    //Transformable::move(direction * speedX / sqrt(direction.x * direction.x + direction.y * direction.y));
}

void Hero::attack() {

}

void Hero::animate() {
    if(clock.getElapsedTime() >= sf::milliseconds(125)){
        clock.restart();
        /*if(actualFrame < textureFrame.size() - 1)
            actualFrame++;
        else
            actualFrame = 0;
        setTextureRect(textureFrame[actualFrame]);*/
        actualFrame < 4 ? actualFrame++ : actualFrame = 0;
        setTextureRect(sf::IntRect(actualFrame * 80 + revert * 400, 0, 80, 86));
    }
}

void Hero::action(GameCharacter &player) {

}

void Hero::eatsweet() {
    sweetCount++;
    std::cout<< sweetCount;
}