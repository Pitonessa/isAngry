//
// Created by Emanuele Casciaro on 16/09/2019.
//

#ifndef ISANGRY_GAMECHARACTER_H
#define ISANGRY_GAMECHARACTER_H

#include "SFML/Graphics.hpp"

class GameCharacter : public sf::Sprite {
public:
    virtual void action(GameCharacter& player) = 0;

protected:
    GameCharacter(float speed, sf::Texture& texture);
    void die();
    virtual void attack() = 0;
    float speed;
    std::vector<sf::IntRect> frameList;
    float previusDirection = 1;
};


#endif //ISANGRY_GAMECHARACTER_H
