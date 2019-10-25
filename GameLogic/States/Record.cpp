//
// Created by mac on 18/10/19.
//

#include "Record.h"

Record::Record(GameEngine *gameEngine): Screen(),gameEngine(gameEngine){
    gameEngine->Clear();
    gameEngine->setStars(std::vector<Star*>());
    gameEngine->setMenu(new Menu(Menu::CENTERED));
}

void Record::update() {

}

