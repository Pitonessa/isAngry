//
// Created by Emanuele Casciaro on 16/09/2019.
//

#ifndef ISANGRY_HERO_H
#define ISANGRY_HERO_H


#include "../GameCharacter.h"
#include "../../GUI/Subject.h"

class Hero : public GameCharacter, public Subject {
public:
    Hero(float speed, sf::Vector2f position);
    void move(sf::Vector2f direction);
    void attack() override;
    void animate() override;
    void action(GameCharacter& hero) override;
    void eatSweet();

    static bool loadTexture();

    void notify() override;

private:
    //Gun* weapon;
    int sweetCount {0};
    int actualFrame {0};
    static sf::Texture* heroTexture;
    float rof {0.1};
    sf::Clock fireClock;

};


#endif //ISANGRY_HERO_H
