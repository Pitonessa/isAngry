//
// Created by mac on 18/09/19.
//

#include "Archer.h"

sf::Texture* Archer::archerTexture = nullptr;

Archer::Archer(float speed, sf::Vector2f position):GameCharacter(speed, *Archer::archerTexture) {
    setPosition(position);
    setTextureRect(sf::IntRect(0,0,80,86));
    setPosition(position);

}
 void Archer::attack() {}

void Archer::animate() {

}
void Archer::action(GameCharacter& hero) {

}

bool Archer::loadTexture() {
    archerTexture = new sf::Texture;
    return archerTexture->loadFromFile("../Res/enemy_spritesheet.png");
}