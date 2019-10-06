//
// Created by Emanuele Casciaro on 16/09/2019.
//

#ifndef ISANGRY_GAMECHARACTER_H
#define ISANGRY_GAMECHARACTER_H

#include "SFML/Graphics.hpp"
#include <cmath>

class GameCharacter : public sf::Sprite {
public:
    virtual void action(GameCharacter& player) = 0;
    virtual void animate() = 0;
    void fixHeight(float groundLevel);
    sf::Clock clock;
    sf::Clock gravityClock;
    void die();
    virtual bool takeDamage();
    int getDirection();
    void jump();
    virtual bool attack() = 0;
    virtual void move(sf::Vector2f direction);

protected:
    GameCharacter(float speed, sf::Texture& texture);
    float speedX;
    std::vector<sf::IntRect> frameList;
    float previusDirection = 1;
    int revert {0};
    sf::Vector2f speed;
    static sf::Vector2f gravity;
    void setRevert(sf::Vector2f direction);


};


#endif //ISANGRY_GAMECHARACTER_H
