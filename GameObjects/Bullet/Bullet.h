//
// Created by Emanuele Casciaro on 16/09/2019.
//

#ifndef ISANGRY_BULLET_H
#define ISANGRY_BULLET_H


#include <SFML/Graphics/Sprite.hpp>
#include "../GameObject.h"

class Bullet : public GameObject {
public:
    Bullet(sf::Texture& texture, sf::Vector2f pos, float speed,sf::Vector2f direction);
    void update(GameCharacter* hero) override;

private:
    sf::Vector2f direction;
};


#endif //ISANGRY_BULLET_H
