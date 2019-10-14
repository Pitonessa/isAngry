//
// Created by mac on 18/09/19.
//

#include "Watcher.h"

sf::Texture* Watcher::watcherTexture = nullptr;

Watcher::Watcher(float speed, sf::Vector2f position) : GameCharacter(speed, *Watcher::watcherTexture) {
    setTextureRect(sf::IntRect(680* actualframe,0,680,472));
    setPosition(position);
}

bool Watcher::attack() {
    return true;
}

void Watcher::animate() {
    if(actualframe>=39)
        actualframe = 0;
    else
        actualframe++;
        setTextureRect(sf::IntRect(680 * (actualframe / 4),472 * revert,680,472));
}

Bullet* Watcher::action(GameCharacter& hero) {
    sf::Vector2f center(
            getPosition().x + getGlobalBounds().width / 2,
            getPosition().y + getGlobalBounds().height / 2
            );
    sf::Vector2f heroCenter(
            hero.getPosition().x + hero.getGlobalBounds().width / 2,
            hero.getPosition().y + hero.getGlobalBounds().height / 2
            );
    sf::Vector2f distance = (heroCenter - center);
    setRevert(-distance);
    float length = sqrt(distance.x*distance.x + distance.y * distance.y);
    if(length<800 && length>200)
        fadeout();
    else
            fadein();
        fadein();
    return nullptr;
}

void Watcher::fadein() {
    if(alpha<255){
        alpha++;
        setColor(sf::Color(255,255,255,alpha));
    }

}
void Watcher::fadeout() {
    if(alpha > 30){
        alpha--;
        setColor(sf::Color(255,255,255,alpha));
    }
}
bool Watcher::loadTexture() {
    watcherTexture = new sf::Texture;
    return watcherTexture->loadFromFile("../Res/dino_idle_original.png");
}
