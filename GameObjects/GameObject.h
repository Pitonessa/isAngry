//
// Created by Emanuele Casciaro on 19/09/2019.
//

#ifndef ISANGRY_GAMEOBJECT_H
#define ISANGRY_GAMEOBJECT_H


#include "SFML/Graphics.hpp"
#include "../GameCharacter/GameCharacter.h"

class GameObject : public sf::Sprite {
public:
    virtual void update(GameCharacter * hero) = 0;
protected:
    explicit GameObject(float s, sf::Texture& texture, sf::Vector2f position);
    GameObject();
    float speed;

};


#endif //ISANGRY_GAMEOBJECT_H
