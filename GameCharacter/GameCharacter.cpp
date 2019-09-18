//
// Created by Emanuele Casciaro on 16/09/2019.
//

#include "GameCharacter.h"

const sf::Vector2f GameCharacter::directionUp = sf::Vector2f(0, -1);
const sf::Vector2f GameCharacter::directionDown = sf::Vector2f(0, 1);
const sf::Vector2f GameCharacter::directionLeft = sf::Vector2f(-1, 0);
const sf::Vector2f GameCharacter::directionRight = sf::Vector2f(1, 0);

GameCharacter::GameCharacter(float speed, sf::Texture& texture) : Sprite(texture), speed(speed) {

}