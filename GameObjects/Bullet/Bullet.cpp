//
// Created by Emanuele Casciaro on 16/09/2019.
//

#include "Bullet.h"

Bullet::Bullet(sf::Texture &texture, sf::Vector2f pos, float speed) : GameObject(speed, texture) {
    setPosition(pos);
    setScale(sf::Vector2f(0.25, 0.25));
}

void Bullet::update() {
    move( speed * sf::Vector2f(1, 0));
}