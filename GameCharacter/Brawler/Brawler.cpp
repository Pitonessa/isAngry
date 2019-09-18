//
// Created by mac on 18/09/19.
//

#include <iostream>
#include "Brawler.h"



Brawler::Brawler(float speed, sf::Texture &Texture, sf::Vector2f position):GameCharacter(speed,Texture) {
    setPosition(position);
    setTextureRect(sf::IntRect(0,0,80,86));
    setPosition(position);

}
void Brawler::attack() {}
void Brawler::move(const GameCharacter &hero) {

    sf::Vector2f distance = hero.getPosition()- getPosition();
    distance = distance / sqrt(distance.x * distance.x + distance.y * distance.y);
    setPosition(getPosition()+distance*speed);


    std::cout<<distance.x<<std::endl<<distance.y<<std::endl;
}