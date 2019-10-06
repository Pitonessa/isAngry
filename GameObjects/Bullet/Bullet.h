//
// Created by Emanuele Casciaro on 16/09/2019.
//

#ifndef ISANGRY_BULLET_H
#define ISANGRY_BULLET_H


#include <SFML/Graphics/Sprite.hpp>
#include "../GameObject.h"

class Bullet : public GameObject {
public:
    Bullet(sf::Vector2f pos, sf::Vector2f speed, float k, bool friendly = false);
    void update() override;
    static bool loadTexture();
    bool isFriendly();
private:
    static sf::Texture* bulletTexture;
    bool friendly;
};


#endif //ISANGRY_BULLET_H
