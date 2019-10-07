//
// Created by mac on 18/09/19.
//

#include "Archer.h"
#include "../../GUI/GameEngine.h"

sf::Texture* Archer::archerTexture = nullptr;

Archer::Archer(float speed, sf::Vector2f position):GameCharacter(speed, *Archer::archerTexture) {
    setPosition(position);
    setTextureRect(sf::IntRect(0,0,80,86));
    setPosition(position);

}
bool Archer::attack() {
    return true;
}

void Archer::animate() {

}
Bullet* Archer::action(GameCharacter& hero) {
    if(fireClock.getElapsedTime().asSeconds() >= rof) {
        float bulletTime = 1;
        float k = GameEngine::getGravity();
        sf::Vector2f distance = hero.getPosition() - getPosition();
        sf::Vector2f speed(
                distance.x / bulletTime,
                -((distance.y / bulletTime) + (k * bulletTime / 2))
                );
        fireClock.restart();
        return new Bullet(getPosition(), speed, k);
    }
    else return nullptr;

}

bool Archer::loadTexture() {
    archerTexture = new sf::Texture;
    return archerTexture->loadFromFile("../Res/enemy_spritesheet.png");
}
