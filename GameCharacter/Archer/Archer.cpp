//
// Created by mac on 18/09/19.
//

#include "Archer.h"
#include "../../GameLogic/GameEngine.h"

sf::Texture* Archer::archerTexture = nullptr;
int Archer::bulletSpeed = 700;

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
        sf::Vector2f distance = hero.getPosition() - getPosition();
        float k = GameEngine::getGravity();
        double a, b, delta = -1;
        do {
            a = ((k) * pow(distance.x, 2)) / (2 * pow(bulletSpeed, 2));
            b = distance.x;
            double c = a - distance.y;

            delta = pow(b, 2) - 4 * a * c;
            bulletSpeed++;
        } while (delta < 0);

        double u2 = (-b - sqrt(delta)) / (2 * a);
        double u1 = (-b - sqrt(delta)) / (2 * a);


        double theta = atan(u2);
        double theta1 = atan(u1);

        sf::Vector2f s;
        s.x = -cos(theta);
        s.y = -sin(theta);
        if (b > 0) {
            s.x = -sin(theta1);
            s.y = -cos(theta1);
        }

        fireClock.restart();

        sf::Vector2f position(
                getPosition().x + getGlobalBounds().width * 0.9,
                getPosition().y
                );
        return new Bullet(position, s * static_cast<float>(bulletSpeed), k);
    }
    else return nullptr;

}

bool Archer::loadTexture() {
    archerTexture = new sf::Texture;
    return archerTexture->loadFromFile("../Res/enemy_spritesheet.png");
}
