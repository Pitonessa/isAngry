//
// Created by mac on 18/10/19.
//

#include "Pause.h"

Pause::Pause(GameEngine *gameEngine): Screen(), gameEngine(gameEngine) {
    gameEngine->setStars(std::vector<Star*>());

}

void Pause::update() {

}

void Pause::handleinput(sf::Keyboard::Key key) {
   gameEngine->navigate(key);


}

