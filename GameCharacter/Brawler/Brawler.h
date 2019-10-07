//
// Created by mac on 18/09/19.
//

#ifndef ISANGRY_BRAWLER_H
#define ISANGRY_BRAWLER_H


#include "../GameCharacter.h"
#include <cmath>



class Brawler : public GameCharacter {
public:
    Brawler(float speed, sf::Vector2f position);
    bool attack() override;
    void move(const GameCharacter&hero);
    Bullet* action(GameCharacter& hero) override;
    void animate() override;
    static bool loadTexture();

private:
    std::vector<sf::IntRect> textureFrame {
        /*
        //IDLE
            sf::IntRect(222, 1183, 213, 428),
            sf::IntRect(0, 2482, 223, 438),
            sf::IntRect(646, 2482, 235, 440),
            */
        //WALK
            sf::IntRect(0, 0, 579, 763),
            sf::IntRect(579, 0, 579, 763),
            sf::IntRect(579 * 2, 0, 579, 763),
            sf::IntRect(579 * 3, 0, 579, 763),
            sf::IntRect(579 * 4, 0, 579, 763),
            sf::IntRect(579 * 5, 0, 579, 763),
            sf::IntRect(579 * 6, 0, 579, 763),
            sf::IntRect(579 * 7, 0, 579, 763),
            sf::IntRect(579 * 8, 0, 579, 763),
            sf::IntRect(579 * 9, 0, 579, 763)
    };
    int actualFrame {0};

    static sf::Texture* brawlerTexture;




};




#endif //ISANGRY_BRAWLER_H
