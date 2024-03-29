//
// Created by Emanuele Casciaro on 16/09/2019.
//

#include <cmath>
#include <iostream>
#include "Bullet.h"

sf::Texture* Bullet::bulletTexture = nullptr;

Bullet::Bullet(sf::Vector2f pos, sf::Vector2f speed, float k, bool frindly) : GameObject(speed, *Bullet::bulletTexture, pos, k), friendly(frindly) {
    setScale(sf::Vector2f(0.25, 0.25));
}

void Bullet::update() {
    //speed.y += gravity.y * clock.restart().asSeconds();
    float deltaT = clock.restart().asSeconds();
    speed.y += gravity.y * deltaT;
    sf::Vector2f offset(
            speed.x * deltaT,
            speed.y * deltaT
            );
    if(friendly) offset.y = 0;
    move(offset);
}

bool Bullet::loadTexture() {
    bulletTexture = new sf::Texture;
    return Bullet::bulletTexture->loadFromFile("../Res/coconut.png");
}

bool Bullet::isFriendly() {
    return friendly;
}