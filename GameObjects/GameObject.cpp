//
// Created by Emanuele Casciaro on 19/09/2019.
//

#include "GameObject.h"

sf::Vector2f GameObject::gravity = sf::Vector2f();

GameObject::GameObject(sf::Vector2f speed, sf::Texture& texture, sf::Vector2f position, float k) : Sprite(texture), speed(speed) {
    GameObject::gravity.y = k;
    setPosition(position);
    clock.restart();
}

bool GameObject::isOut(float groundLevel, sf::View limitView) {
    float x = getPosition().x;
    float y = getPosition().y;
    float leftBoundary = limitView.getCenter().x - limitView.getSize().x / 2;
    float rightBoundary = limitView.getCenter().x + limitView.getSize().x / 2;

    return (
            x >= rightBoundary
            ) || (
                    x + getGlobalBounds().width <= leftBoundary
                    ) || (
                            y >= groundLevel
                            );
}