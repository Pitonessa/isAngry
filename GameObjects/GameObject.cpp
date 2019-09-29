//
// Created by Emanuele Casciaro on 19/09/2019.
//

#include "GameObject.h"

GameObject::GameObject(float s, sf::Texture& texture, sf::Vector2f position) : Sprite(texture), speed(s) {
    setPosition(position);
}
GameObject::GameObject() : speed(0) {}