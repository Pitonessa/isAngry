//
// Created by Emanuele Casciaro on 16/09/2019.
//

#include <cmath>
#include <iostream>
#include "Bullet.h"

Bullet::Bullet(sf::Texture &texture, sf::Vector2f pos, sf::Vector2f speed, float k) : GameObject(speed, texture, pos, k) {
    setScale(sf::Vector2f(0.25, 0.25));
}

void Bullet::update() {
    speed.y += gravity.y * clock.restart().asSeconds();
    move(speed.x, speed.y);
}