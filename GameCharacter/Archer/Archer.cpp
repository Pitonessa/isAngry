//
// Created by mac on 18/09/19.
//

#include "Archer.h"

Archer::Archer(float speed, sf::Texture &Texture, sf::Vector2f position):GameCharacter(speed,Texture) {
    setPosition(position);
    setTextureRect(sf::IntRect(0,0,80,86));
    setPosition(position);

}
 void Archer::attack() {}

void Archer::animate() {

}
void Archer::action(GameCharacter& hero) {

}