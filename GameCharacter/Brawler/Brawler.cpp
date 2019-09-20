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

    sf::Vector2f hPos = hero.getPosition();
    hPos.y += hero.getGlobalBounds().height;
    sf::Vector2f Pos = getPosition();
    Pos.y += getGlobalBounds().height;

    sf::Vector2f distance = hPos - Pos;
    distance = distance / sqrt(distance.x * distance.x + distance.y * distance.y);
    setPosition(getPosition()+distance*speed);
}
void Brawler::action(GameCharacter& player) {
    move(player);
}