//
// Created by Emanuele Casciaro on 16/09/2019.
//

#ifndef ISANGRY_BULLET_H
#define ISANGRY_BULLET_H


#include <SFML/Graphics/Sprite.hpp>

class Bullet : sf::Sprite {
public:
    Bullet(sf::Texture& texture, sf::Vector2f pos);
    void update();

private:
    float speed {12};
};


#endif //ISANGRY_BULLET_H
