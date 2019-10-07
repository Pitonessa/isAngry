//
// Created by Emanuele Casciaro on 16/09/2019.
//

#include "GameCharacter.h"

sf::Vector2f GameCharacter::gravity = sf::Vector2f(0,0.1);

GameCharacter::GameCharacter(float speed, sf::Texture& texture) : Sprite(texture), speedX(speed) {
    clock.restart();
    fireClock.restart();
    gravityClock.restart();
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

 void GameCharacter::move(sf::Vector2f direction) {
     if(direction.x !=0|| direction.y!=0){
         setRevert(direction);
         float GroundLevel= 961.5;
         direction /= sqrt(direction.x * direction.x + direction.y * direction.y);
         GameCharacter::speed += GameCharacter::gravity;
         GameCharacter::speed.x = direction.x * speedX;
         GameCharacter::speed.y += direction.y;
         Transformable::move(speed);

     }



}

void GameCharacter::setRevert(sf::Vector2f direction) {
    if(direction.x != 0)
        direction.x < 0 ? revert = 1 : revert = 0;
}