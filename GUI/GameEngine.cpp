//
// Created by Emanuele Casciaro on 18/09/2019.
//

#include "GameEngine.h"
#include "../GameCharacter/Brawler/Brawler.h"


GameEngine::GameEngine(sf::RenderWindow &mainWindow) : gameWindow(&mainWindow), gameMenu(new Menu(Menu::STYLE::MAIN)) {
    heroTexture = new sf::Texture();
    stalkerTexture = new sf::Texture();
    brawlerTexture = new sf::Texture();
    archerTexture = new sf::Texture();
    bossTexture = new sf::Texture();
    backgroundTexture = new sf::Texture();
    if(!loadTextures()) {
        //TODO TEXTURE NON CARICATE, GESTISCI
    }
    hero = new Hero(5, *heroTexture, sf::Vector2f(100, 100));
    hero->scale(sf::Vector2f(3, 3));
    background.push_back(new sf::Sprite(*backgroundTexture));
    background.push_back(new sf::Sprite(*backgroundTexture));
    float scaleFactor = gameWindow->getView().getSize().y / background[0]->getTextureRect().height;
    background[0]->scale(sf::Vector2f(scaleFactor, scaleFactor));
    background[1]->setPosition(background[0]->getGlobalBounds().width * 2 - 5 , 0);
    background[1]->scale(sf::Vector2f(-scaleFactor, scaleFactor));
    std::cout << background[1]->getPosition().x;
    this->stars = Star::createStars(gameWindow);
    enemies.push_back(new Brawler(3, *brawlerTexture, sf::Vector2f(400, 400)));
}

bool GameEngine::loadTextures() {
    return heroTexture->loadFromFile("../Res/hero_spritesheet.png") &&
            stalkerTexture->loadFromFile("../Res/enemy_spritesheet.png") &&
            brawlerTexture->loadFromFile("../Res/enemy_spritesheet.png") &&
            archerTexture->loadFromFile("../Res/enemy_spritesheet.png") &&
            bossTexture->loadFromFile("../Res/enemy_spritesheet.png") &&
            backgroundTexture->loadFromFile("../Res/candy3.jpeg");
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
            for (auto b : background)
                gameWindow->draw(*b);
            gameWindow->draw(*hero);
            for (auto enemy : enemies) {
                enemy->action(*hero);
                gameWindow->draw(*enemy);
            }
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
                gameState = 2;
                break;
            case MenuItem::TYPE::RECORD:
                gameState = 1;
                break;
            case MenuItem::TYPE::EXIT:
                gameWindow->close();
                break;
            case MenuItem::TYPE::QUIT:
                gameState = 0;
                break;
            case MenuItem::TYPE::RESUME:
                gameState = 2;
                break;
            default:

                break;
        }
    }
}

void GameEngine::moveHero(sf::Vector2f direction) {
    hero->move(direction);
}