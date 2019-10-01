//
// Created by Emanuele Casciaro on 16/09/2019.
//

#ifndef ISANGRY_BULLET_H
#define ISANGRY_BULLET_H


#include <SFML/Graphics/Sprite.hpp>
#include "../GameObject.h"

class Bullet : public GameObject {
public:
    Bullet(sf::Texture& texture, sf::Vector2f pos, sf::Vector2f speed, float k);
    void update() override;
    bool isOut(sf::View view, float ground);
private:
};


#endif //ISANGRY_BULLET_H
