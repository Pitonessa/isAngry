//
// Created by mac on 18/10/19.
//

#include "MainMenu.h"
#include "Play.h"


MainMenu::MainMenu(GameEngine *gameEngine) : Screen(), gameEngine(gameEngine){
    gameEngine->Clear();
    gameEngine->setMenu(new Menu(Menu::STYLE::MAIN));
    gameEngine->setStars(Star::createStars(&gameEngine->getWindow()));
}

void MainMenu::update() {
   for(auto j : gameEngine->getStar()) j->updateStar();

}

void MainMenu::handleinput(sf::Keyboard::Key key) {

    switch(key){
        case sf::Keyboard:: Up :
            gameEngine->gameMenu->forward();

            break;
        case sf::Keyboard:: Down :
            gameEngine->gameMenu->backward();
            break;
        case sf::Keyboard:: Enter :
            switch (gameEngine->gameMenu->getAction()) {
                case MenuItem::TYPE::START:
                    // gameEngine->setscreen(new Play());

                case MenuItem::TYPE::RECORD:
                    // gameEngine->setscreen(new Record());
                    break;
                    break;
                case MenuItem::TYPE::EXIT:
                    gameEngine->getWindow().close();
                    break;

                    default:

                    break;
            }
            break;
        default:
            std::cout<<"Tasto non Configurato"<<std::endl;
            break;


    }

}
