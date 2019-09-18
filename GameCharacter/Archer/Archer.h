//
// Created by mac on 18/09/19.
//

#ifndef ISANGRY_ARCHER_H
#define ISANGRY_ARCHER_H

#include "../GameCharacter.h"



class Archer: public GameCharacter {
public:
    Archer(float speed, sf::Texture& Texture, sf::Vector2f position);
    void attack() override;



};


#endif //ISANGRY_ARCHER_H
