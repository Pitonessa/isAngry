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
  void animated();

private:
    sf::Clock c;
    std::vector<sf::IntRect> textureFrame {
            sf::IntRect(0,0, 579, 763),
            sf::IntRect(579,0 , 579, 763),
            sf::IntRect(579*2,0 , 579, 763),
            sf::IntRect(579*3,0, 579, 763),
            sf::IntRect(579*4,0 , 579, 763),
            sf::IntRect(579*5,0 , 579, 763),
            sf::IntRect(579*6,0 , 579, 763),
            sf::IntRect(579*7,0 , 579, 763),
            sf::IntRect(579*8,0 , 579, 763)
    };
    int actualFrame {0};




};




#endif //ISANGRY_BRAWLER_H
