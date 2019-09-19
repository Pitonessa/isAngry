//
// Created by Emanuele Casciaro on 18/09/2019.
//

#include "GameEngine.h"


GameEngine::GameEngine(sf::RenderWindow &mainWindow) : gameWindow(&mainWindow), gameMenu(new Menu(Menu::STYLE::MAIN)) {
    heroTexture = new sf::Texture();
    stalkerTexture = new sf::Texture();
    brawlerTexture = new sf::Texture();
    archerTexture = new sf::Texture();
    bossTexture = new sf::Texture();
    if(!loadTextures()) {
        //TODO TEXTURE NON CARICATE, GESTISCI
    }
    hero = new Hero(5, *heroTexture, sf::Vector2f(100, 100));
    this->stars = Star::createStars(gameWindow);
}

bool GameEngine::loadTextures() {
    return heroTexture->loadFromFile("../Res/hero_spritesheet.png") &&
            stalkerTexture->loadFromFile("../Res/enemy_spritesheet.png") &&
            brawlerTexture->loadFromFile("../Res/enemy_spritesheet.png") &&
            archerTexture->loadFromFile("../Res/enemy_spritesheet.png") &&
            bossTexture->loadFromFile("../Res/enemy_spritesheet.png");
}

void GameEngine::drawWorld() const {
    switch (gameState) {
        case 0:                                     //MAIN MENU
            for (auto star : stars){
                star->updateStar();
                gameWindow->draw(*star);
            }
            gameMenu->draw(*gameWindow);
            break;
        case 1:                                     //RECORD MENU
            break;
        case 2:                                     //GAME
            gameWindow->draw(*hero);
            for (auto enemy : enemies)
                gameWindow->draw(*enemy);
            for (auto prop : props)
                gameWindow->draw(*prop);
            for (auto bullet : bullets)
                gameWindow->draw(*bullet);
            break;
        case 3:                                     //PAUSE
            gameWindow->draw(*hero);
            for (auto enemy : enemies)
                gameWindow->draw(*enemy);
            for (auto prop : props)
                gameWindow->draw(*prop);
            for (auto bullet : bullets)
                gameWindow->draw(*bullet);
            break;
    }
}

void GameEngine::navigate(sf::Keyboard::Key key) {
    if ((key == sf::Keyboard::W) || (key == sf::Keyboard::Up))
        gameMenu->backward();
    else if ((key == sf::Keyboard::S) || (key == sf::Keyboard::Down))
        gameMenu->forward();
    else if(key == sf::Keyboard::Enter) {
        switch (gameMenu->getAction()) {
            case MenuItem::TYPE::START:

                break;
        }
    }
}