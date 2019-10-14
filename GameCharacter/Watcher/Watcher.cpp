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
    if(actualframe==9)
        actualframe=0;
    else
        actualframe++;
    setTextureRect(sf::IntRect(680*actualframe + 6800 * revert,0,680,472));
}

void Watcher::action(GameCharacter& hero) {
    sf::Vector2f distance = ( hero.getPosition()-getPosition());
    setRevert(-distance);
    float length = sqrt(distance.x*distance.x + distance.y * distance.y);
    if(length<800 && length>200)
        fadeout();
    else
            fadein();
}

void Watcher::fadein() {
    if(alpha<255){
        alpha++;
        setColor(sf::Color(255,255,255,alpha));
    }

}
void Watcher::fadeout() {
    if(alpha>0){
        alpha--;
        setColor(sf::Color(255,255,255,alpha));
    }
}
bool Watcher::loadTexture() {
    watcherTexture = new sf::Texture;
    return watcherTexture->loadFromFile("../Res/dino_idle_original.png");
}
