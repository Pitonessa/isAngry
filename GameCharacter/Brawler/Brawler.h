//
// Created by mac on 18/09/19.
//

#ifndef ISANGRY_BRAWLER_H
#define ISANGRY_BRAWLER_H


#include "../GameCharacter.h"
#include <cmath>



class Brawler: public GameCharacter {
public:
    Brawler(float speed, sf::Texture& Texture, sf::Vector2f position);
    void attack() override;
  void move(const GameCharacter&hero);
  void action(GameCharacter& hero) override;
  void animate() override;

private:
    sf::Clock c;
    std::vector<sf::IntRect> textureFrame {
        /*
        //IDLE
            sf::IntRect(222, 1183, 213, 428),
            sf::IntRect(0, 2482, 223, 438),
            sf::IntRect(646, 2482, 235, 440),
            */
        //WALK
            sf::IntRect(1567, 2046, 193, 436),
            sf::IntRect(1075, 2482, 200, 442),
            sf::IntRect(453, 2482, 193, 440),
            sf::IntRect(1030, 1183, 180, 431),
            sf::IntRect(1030, 2046, 184, 434),
            sf::IntRect(1214, 2046, 176, 435),
    };
    int actualFrame {0};




};




#endif //ISANGRY_BRAWLER_H
