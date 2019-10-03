//
// Created by Emanuele Casciaro on 16/09/2019.
//

#include <cmath>
#include <iostream>
#include "Bullet.h"

sf::Texture* Bullet::bulletTexture = nullptr;

Bullet::Bullet(sf::Vector2f pos, sf::Vector2f speed, float k) : GameObject(speed, *Bullet::bulletTexture, pos, k) {
    setScale(sf::Vector2f(0.25, 0.25));
}

void Bullet::update() {
    speed.y += gravity.y * clock.restart().asSeconds();
    move(speed);
}

bool Bullet::loadTexture() {
    bulletTexture = new sf::Texture;
    return Bullet::bulletTexture->loadFromFile("../Res/coconut.png");
}