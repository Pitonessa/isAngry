//
// Created by mac on 18/09/19.
//

#ifndef ISANGRY_BRAWLER_H
#define ISANGRY_BRAWLER_H


#include "../GameCharacter.h"



class Brawler: public GameCharacter {
public:
    Brawler(float speed, sf::Texture& Texture, sf::Vector2f position);
    void attack() override;



};



#endif //ISANGRY_BRAWLER_H