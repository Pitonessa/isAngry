//
// Created by mac on 18/09/19.
//

#include "Brawler.h"


Brawler::Brawler(float speed, sf::Texture &Texture, sf::Vector2f position):GameCharacter(speed,Texture) {
    setPosition(position);
    setTextureRect(sf::IntRect(0,0,80,86));
    setPosition(position);

}
void Brawler::attack() {}