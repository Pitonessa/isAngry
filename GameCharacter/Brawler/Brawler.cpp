//
// Created by mac on 18/09/19.
//

#include <iostream>
#include "Brawler.h"



Brawler::Brawler(float speed, sf::Texture &Texture, sf::Vector2f position):GameCharacter(speed,Texture) {
    setPosition(position);
    setTextureRect(textureFrame[actualFrame]);
    setPosition(position);
    c.restart();
}
void Brawler::attack() {}
void Brawler::move(const GameCharacter &hero) {

    sf::Vector2f distance = hero.getPosition()- getPosition();
    distance = distance / sqrt(distance.x * distance.x + distance.y * distance.y);
    setPosition(getPosition()+distance*speed);
}
void Brawler::animated(){
    if (c.getElapsedTime()>=sf::milliseconds(80)){
        if(actualFrame<textureFrame.size()-1)
            actualFrame++;
        else
            actualFrame=0;
        setTextureRect(textureFrame[actualFrame]);
        c.restart();

    }

}