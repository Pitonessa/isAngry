//
// Created by Emanuele Casciaro on 19/09/2019.
//

#ifndef ISANGRY_GAMEOBJECT_H
#define ISANGRY_GAMEOBJECT_H


#include "SFML/Graphics.hpp"

class GameObject : public sf::Sprite {

protected:
    explicit GameObject(float s, sf::Texture& texture);
    GameObject();
    virtual void update() = 0;
    float speed;

};


#endif //ISANGRY_GAMEOBJECT_H
