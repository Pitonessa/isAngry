//
// Created by Emanuele Casciaro on 19/09/2019.
//

#include "GameObject.h"

GameObject::GameObject(float s, sf::Texture& texture) : Sprite(texture), speed(s) {}
GameObject::GameObject() : speed(0) {}