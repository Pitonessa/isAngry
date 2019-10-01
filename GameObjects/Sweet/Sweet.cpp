//
// Created by Emanuele Casciaro on 29/09/2019.
//

#include "Sweet.h"

Sweet::Sweet(sf::Vector2f position, sf::Texture *texture): GameObject(sf::Vector2f(), *texture, position, 0) {
    sf::Vector2f center = getPosition();
    center.x += getGlobalBounds().width / 2;
    center.y += getGlobalBounds().height / 2;
    setOrigin(center);
    setPosition(position);
}

void Sweet::update() {

}
