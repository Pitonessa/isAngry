//
// Created by Emanuele Casciaro on 18/09/2019.
//

#include <thread>
#include "GameEngine.h"
#include "../GameCharacter/Brawler/Brawler.h"
#include "../GameCharacter/Factories/GameFactory.h"
#include "../GameObjects/Sweet/Sweet.h"


GameEngine::GameEngine(sf::RenderWindow &mainWindow) : gameWindow(&mainWindow), gameMenu(new Menu(Menu::STYLE::MAIN)) {
    //todo metti il menu
    gameSpeed = 1;
    std::cout << gameSpeed << std::endl;
    if(!loadTextures()) {
        //TODO TEXTURE NON CARICATE, GESTISCI
    }
    hero = new Hero(5, *heroTexture, sf::Vector2f(100, 100));
    hero->scale(sf::Vector2f(3, 3));
    background.push_back(new sf::Sprite(*backgroundTexture));
    background.push_back(new sf::Sprite(*backgroundTexture));
    background.push_back(new sf::Sprite(*backgroundTexture));
    background.push_back(new sf::Sprite(*backgroundTexture));
    float scaleFactor = gameWindow->getView().getSize().y / background[0]->getTextureRect().height;
    background[0]->scale(sf::Vector2f(scaleFactor, scaleFactor));
    background[1]->setPosition(background[0]->getGlobalBounds().width * 2, 0);
    background[1]->scale(sf::Vector2f(-scaleFactor, scaleFactor));
    background[2]->setPosition(background[0]->getGlobalBounds().width * 2, 0);
    background[2]->scale(sf::Vector2f(scaleFactor, scaleFactor));
    background[3]->setPosition(background[0]->getGlobalBounds().width * 4, 0);
    background[3]->scale(sf::Vector2f(-scaleFactor, scaleFactor));
    this->stars = Star::createStars(gameWindow);
    enemies.push_back(new Brawler(1, *brawlerTexture, sf::Vector2f(400, 400)));
    enemies[0]->scale(sf::Vector2f(0.33, 0.33));
    props.push_back(new Sweet(sf::Vector2f(2000,1000),candyTexture));
    props[0]->scale(0.10,0.10);
    bullets.push_back(new Bullet(*bossTexture, sf::Vector2f(500, 500), sf::Vector2f(20, -10), 100));


    gameClock.restart();
}

bool GameEngine::loadTextures() {
    heroTexture = new sf::Texture();
    stalkerTexture = new sf::Texture();
    brawlerTexture = new sf::Texture();
    archerTexture = new sf::Texture();
    bossTexture = new sf::Texture();
    backgroundTexture = new sf::Texture();
    candyTexture = new sf::Texture();
    return heroTexture->loadFromFile("../Res/isAnimatedFull.png") &&
            stalkerTexture->loadFromFile("../Res/dino.png") &&
            brawlerTexture->loadFromFile("../Res/lanter_walk_original.png") &&
            archerTexture->loadFromFile("../Res/enemy_spritesheet.png") &&
            bossTexture->loadFromFile("../Res/coconut.png") &&
            candyTexture->loadFromFile("../Res/lolly.png") &&
            backgroundTexture->loadFromFile("../Res/Background1.png");
}

void GameEngine::drawWorld() {
        if (gameClock.getElapsedTime() >= sf::seconds(1.0f / 60)) {
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
                    hero->animate();
                    gameWindow->draw(*hero);
                    for (auto enemy : enemies) {
                        enemy->action(*hero);
                        enemy->animate();
                        enemy->fixHeight(961.5);
                        gameWindow->draw(*enemy);
                    }

                    for (auto prop : props){
                        prop->update();
                        gameWindow->draw(*prop);
                    }
                    for (auto i = bullets.begin(); i < bullets.end(); i++) {
                       //this->bullets[]
                    }
                    for (auto bullet : bullets){
                        bullet->update();
                        /*if (bullet->isOut(gameWindow->getView(), 1000)) {
                            //auto i = bullets.erase()
                        }*/
                        gameWindow->draw(*bullet);

                    }
                    moveView();
                    break;
                case 3:                                     //PAUSE
                    gameWindow->draw(*hero);
                    for (auto enemy : enemies)
                        gameWindow->draw(*enemy);
                    for (auto prop : props)
                        gameWindow->draw(*prop);
                    for (auto bullet : bullets) {
                        gameWindow->draw(*bullet); }
                    break;
            }
        }
    //return true;
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
                restartClock();
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
                restartClock();
                break;
            default:

                break;
        }
    }
}

void GameEngine::moveHero(sf::Vector2f direction) {
    hero->move(direction);
    hero->fixHeight(961.5);
}

void GameEngine::addEnemy(GameCharacter &enemy) {
    enemies.push_back(&enemy);
}

void GameEngine::setHeroPos(float x, float y) {
    hero->setPosition(x, y);
}

const sf::RenderWindow& GameEngine::getWindow() {
    return *gameWindow;
}

void GameEngine::moveView() {
    sf::View temp = gameWindow->getView();
    temp.move(0.5f * gameSpeed, 0);
    for (auto i : background) {
        if (i->getPosition().x + 2 * i->getGlobalBounds().width < temp.getCenter().x) {
            i->move(4 * i->getGlobalBounds().width, 0);
            std::cout << "Background moved" << std::endl;
        }
    }
    gameWindow->setView(temp);
}

void GameEngine::restartClock() {
    hero->clock.restart();
    for (auto enemy : enemies)
        enemy->clock.restart();
    for (auto obj : props)
        obj->clock.restart();
    for (auto bullet : bullets)
        bullet->clock.restart();
}

void GameEngine::herojump() {

}