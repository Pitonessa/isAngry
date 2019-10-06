//
// Created by mac on 18/09/19.
//

#include "Watcher.h"

sf::Texture* Watcher::watcherTexture = nullptr;

Watcher::Watcher(float speed, sf::Vector2f position) : GameCharacter(speed, *Watcher::watcherTexture) {
    setPosition(position);
    setTextureRect(sf::IntRect(0,0,80,86));
    setPosition(position);
}

bool Watcher::attack() {
    return true;
}

void Watcher::animate() {}

void Watcher::action(GameCharacter& hero) {}

bool Watcher::loadTexture() {
    watcherTexture = new sf::Texture;
    return watcherTexture->loadFromFile("../Res/dino.png");
}
