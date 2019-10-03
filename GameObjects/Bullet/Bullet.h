//
// Created by Emanuele Casciaro on 16/09/2019.
//

#ifndef ISANGRY_BULLET_H
#define ISANGRY_BULLET_H


#include <SFML/Graphics/Sprite.hpp>
#include "../GameObject.h"

class Bullet : public GameObject {
public:
    Bullet(sf::Vector2f pos, sf::Vector2f speed, float k);
    void update() override;
    static bool loadTexture();
private:
    static sf::Texture* bulletTexture;
};


#endif //ISANGRY_BULLET_H
