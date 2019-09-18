//
// Created by Emanuele Casciaro on 16/09/2019.
//

#ifndef ISANGRY_GAMECHARACTER_H
#define ISANGRY_GAMECHARACTER_H

#include "SFML/Graphics.hpp"

class GameCharacter : public sf::Sprite {
public:
    static const sf::Vector2f directionUp;
    static const sf::Vector2f directionDown;
    static const sf::Vector2f directionLeft;
    static const sf::Vector2f directionRight;
protected:
    GameCharacter(float speed, sf::Texture& texture);
    void die();
    virtual void attack() = 0;
    float speed;
};


#endif //ISANGRY_GAMECHARACTER_H
