//
// Created by mac on 18/10/19.
//

#include "MainMenu.h"


MainMenu::MainMenu(GameEngine *gameEngine) : Screen(), gameEngine(gameEngine){
    gameEngine->setHero(nullptr);
    gameEngine->setMenu(new Menu(Menu::STYLE::MAIN));
    gameEngine->Clear();
    gameEngine->setStars(Star::createStars(&gameEngine->getWindow()));
}

void MainMenu::update() {
   for(auto j : gameEngine->getStar()) j->updateStar();
}