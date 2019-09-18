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
    void animate();

private:
    //Gun* weapon;
    int sweetCount {0};
    sf::Clock c;
    std::vector<sf::IntRect> textureFrame {
            sf::IntRect(0, 0, 80, 86),
            sf::IntRect(0,86 , 80, 86)
    };
    int actualFrame {0};

};


#endif //ISANGRY_HERO_H
