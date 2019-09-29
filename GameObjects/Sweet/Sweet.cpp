//
// Created by Emanuele Casciaro on 29/09/2019.
//

#include "Sweet.h"

Sweet::Sweet(sf::Vector2f position, sf::Texture *texture): GameObject(0,*texture,position) {
}

void Sweet::update(GameCharacter* character) {
    Hero* hero= dynamic_cast<Hero*>(character);

    if(getGlobalBounds().intersects(hero->getGlobalBounds())){
        setScale(0,0);
        hero->eatsweet();


    }

}
