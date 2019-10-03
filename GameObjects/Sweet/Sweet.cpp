//
// Created by Emanuele Casciaro on 29/09/2019.
//

#include "Sweet.h"

sf::Texture* Sweet::candyTexture = nullptr;

Sweet::Sweet(sf::Vector2f position) : GameObject(sf::Vector2f(0, 0), *Sweet::candyTexture, position, 0) {
    sf::Vector2f center = getPosition();
    center.x += getGlobalBounds().width / 2;
    center.y += getGlobalBounds().height / 2;
    setOrigin(center);
    setPosition(position);
}

void Sweet::update() {}

bool Sweet::loadTexture() {
    candyTexture = new sf::Texture;
    return candyTexture->loadFromFile("../Res/candy6.png");
}