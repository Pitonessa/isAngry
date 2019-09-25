//
// Created by Emanuele Casciaro on 16/09/2019.
//

#ifndef ISANGRY_HERO_H
#define ISANGRY_HERO_H


#include "../GameCharacter.h"

class Hero : public GameCharacter {
public:
    Hero(float speed, sf::Texture &texture, sf::Vector2f position);
    void move(std::vector<sf::Vector2f> directions);
    void move(sf::Vector2f direction);
    void attack() override;
    void animate() override;
    void action(GameCharacter& hero) override;

private:
    //Gun* weapon;
    int sweetCount {0};
    sf::Clock c;
    int actualFrame {0};

};


#endif //ISANGRY_HERO_H
