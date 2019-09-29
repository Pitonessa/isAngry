//
// Created by Emanuele Casciaro on 16/09/2019.
//

#include <cmath>
#include "Bullet.h"

Bullet::Bullet(sf::Texture &texture, sf::Vector2f pos, float speed, sf::Vector2f direction) : GameObject(speed, texture,pos) ,direction(direction){
    setScale(sf::Vector2f(0.25, 0.25));
    this->direction/=sqrt(direction.x * direction.x + direction.y+direction.y);
}

void Bullet::update(GameCharacter* hero) {
    move(direction*speed);
}