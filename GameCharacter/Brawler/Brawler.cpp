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
    float mag = distance.x * distance.x + distance.y * distance.y;
    if (mag >= 50) {
        distance = distance / sqrt(mag);
        Sprite::move(distance * speed);
    }
}
void Brawler::animate(){
    if (c.getElapsedTime()>=sf::milliseconds(1000/6)){
        if(actualFrame<textureFrame.size()-1)
            actualFrame++;
        else
            actualFrame=0;
        setTextureRect(textureFrame[actualFrame]);
        c.restart();

    }

}

void Brawler::action(GameCharacter& hero) {
    move(hero);
}