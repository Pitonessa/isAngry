//
// Created by Emanuele Casciaro on 19/09/2019.
//

#ifndef ISANGRY_GAMEOBJECT_H
#define ISANGRY_GAMEOBJECT_H


#include "SFML/Graphics.hpp"

class GameObject : public sf::Sprite {
public:
    virtual void update() = 0;
    static sf::Vector2f gravity;
    bool isOut(sf::View limitView, float groundLevel);
    sf::Clock clock;
protected:
    explicit GameObject(sf::Vector2f s, sf::Texture& texture, sf::Vector2f position, float k);
    sf::Vector2f speed;
    //float speed;

};


#endif //ISANGRY_GAMEOBJECT_H
