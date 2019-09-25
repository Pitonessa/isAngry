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
            sf::IntRect(0, 0, 680, 472),
            sf::IntRect(680, 0, 680, 472),
            sf::IntRect(680 * 2, 0, 680, 472),
            sf::IntRect(680 * 3, 0, 680, 472),
            sf::IntRect(680 * 4, 0, 680, 472),
            sf::IntRect(680 * 5, 0, 680, 472),
            sf::IntRect(680 * 6, 0, 680, 472),
            sf::IntRect(680 * 7, 0, 680, 472),
            sf::IntRect(680 * 8, 0, 680, 472),
            sf::IntRect(680 * 9, 0, 680, 472)
    };
    int actualFrame {0};




};




#endif //ISANGRY_BRAWLER_H
