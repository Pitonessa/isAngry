//
// Created by Emanuele Casciaro on 16/09/2019.
//

#include "Bullet.h"

Bullet::Bullet(sf::Texture &texture, sf::Vector2f pos) : sf::Sprite(texture) {
    setPosition(pos);
    setScale(sf::Vector2f(0.25, 0.25));
}

void Bullet::update() {
    setPosition(
            getPosition() + speed * sf::Vector2f(1, 0)
            );
}