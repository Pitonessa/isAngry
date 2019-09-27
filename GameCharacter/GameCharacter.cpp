//
// Created by Emanuele Casciaro on 16/09/2019.
//

#include "GameCharacter.h"

sf::Vector2f GameCharacter::gravity= sf::Vector2f(0,0.1);

GameCharacter::GameCharacter(float speed, sf::Texture& texture) : Sprite(texture), speedX(speed) {


}