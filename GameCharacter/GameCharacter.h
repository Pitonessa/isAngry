//
// Created by Emanuele Casciaro on 16/09/2019.
//

#ifndef ISANGRY_GAMECHARACTER_H
#define ISANGRY_GAMECHARACTER_H

#include "SFML/Graphics.hpp"

class GameCharacter : public sf::Sprite {
public:
    virtual void action(GameCharacter& player) = 0;
    virtual void animate() = 0;

protected:
    GameCharacter(float speed, sf::Texture& texture);
    void die();
    virtual void attack() = 0;
    float speedX;
    std::vector<sf::IntRect> frameList;
    float previusDirection = 1;
    int revert {0};
};


#endif //ISANGRY_GAMECHARACTER_H
