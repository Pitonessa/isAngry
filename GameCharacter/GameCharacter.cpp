//
// Created by Emanuele Casciaro on 16/09/2019.
//

#include "GameCharacter.h"

sf::Vector2f GameCharacter::gravity = sf::Vector2f(0,0.1);

GameCharacter::GameCharacter(float speed, sf::Texture& texture) : Sprite(texture), speedX(speed) {
    clock.restart();
    fireClock.restart();
}

void GameCharacter::fixHeight(float groundLevel) {
    if(groundLevel-(getPosition().y + getGlobalBounds().height) <= 0){
        if (speed.y > 0)
            speed.y = 0;
        setPosition(getPosition().x, groundLevel - getGlobalBounds().height);
    }

}

bool GameCharacter::takeDamage() {
    return true;
}

void GameCharacter::die() {

}

int GameCharacter::getDirection() {
    return revert == 0 ? 1 : -1;
}
void GameCharacter::jump() {
    speed.y=-35;
}