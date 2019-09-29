//
// Created by Emanuele Casciaro on 29/09/2019.
//

#ifndef ISANGRY_SWEET_H
#define ISANGRY_SWEET_H


#include "../GameObject.h"
#include "../../GameCharacter/Hero/Hero.h"

class Sweet: public GameObject {
public:
    Sweet(sf::Vector2f position, sf::Texture *texture);
    void update(GameCharacter* hero) override;


};


#endif //ISANGRY_SWEET_H
