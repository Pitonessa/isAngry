//
// Created by Emanuele Casciaro on 18/09/2019.
//

#include <thread>
#include "GameEngine.h"
#include "../GameCharacter/Brawler/Brawler.h"
#include "../GameCharacter/Factories/GameFactory.h"
#include "../GameObjects/Sweet/Sweet.h"
#include "../GameCharacter/Archer/Archer.h"
#include "../GameCharacter/Watcher/Watcher.h"


GameEngine::GameEngine(sf::RenderWindow &mainWindow) : gameWindow(&mainWindow), gameMenu(new Menu(Menu::STYLE::MAIN)) {
    //todo metti il menu
    gameSpeed = 1;
    std::cout << gameSpeed << std::endl;
    if(!loadTextures()) {
        //TODO TEXTURE NON CARICATE, GESTISCI
    }
    hero = new Hero(5, sf::Vector2f(100, 100));
    hero->scale(sf::Vector2f(3, 3));
    background.push_back(new sf::Sprite(*backgroundTexture));
    background.push_back(new sf::Sprite(*backgroundTexture));
    float scaleFactor = gameWindow->getView().getSize().y / background[0]->getTextureRect().height;
    background[0]->scale(sf::Vector2f(scaleFactor, scaleFactor));
    background[1]->setPosition(background[0]->getGlobalBounds().width, 0);
    background[1]->scale(sf::Vector2f(scaleFactor, scaleFactor));
    this->stars = Star::createStars(gameWindow);
    enemies.push_back(new Brawler(1, sf::Vector2f(400, 400)));
    enemies[0]->scale(sf::Vector2f(0.33, 0.33));
    props.push_back(new Sweet(sf::Vector2f(2000, 1000)));
    props[0]->scale(0.33, 0.33);

    gameClock.restart();
}

bool GameEngine::loadTextures() {
    backgroundTexture = new sf::Texture();
    return backgroundTexture->loadFromFile("../Res/Background1.png") &&
        Hero::loadTexture() &&
        Archer::loadTexture() &&
        Brawler::loadTexture() &&
        Watcher::loadTexture() &&
        Sweet::loadTexture() &&
        Bullet::loadTexture();
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
                        enemy->fixHeight(1061.5);
                        gameWindow->draw(*enemy);
                    }

                    for (auto prop : props){
                        prop->update();
                        gameWindow->draw(*prop);
                    }

                    for (unsigned long i = 0; i < bullets.size(); i++) {
                        bullets[i]->update();
                        if (bullets[i]->isOut(gameWindow->getView(), 1000) || detectCollision(*bullets[i])) {
                            delete bullets[i];
                            bullets.erase(bullets.begin() + i);
                        }
                        else gameWindow->draw(*bullets[i]);

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
    hero->fixHeight(1061.5);
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
        float pos = i->getPosition().x;
        if (pos + i->getGlobalBounds().width < temp.getCenter().x - temp.getSize().x / 2) {
            i->move(2 * i->getGlobalBounds().width, 0);
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

void GameEngine::heroJump() {

}

void GameEngine::heroAttack() {
    if(hero->attack()) {
        bullets.push_back(new Bullet(hero->getPosition(), sf::Vector2f(20 * (hero->getDirection()), .5), 25, true));
    }

}

bool GameEngine::detectCollision(Bullet &bullet) {
    bool result = false;
    if(bullet.isFriendly()) {
        for (int i = 0; i < enemies.size(); i++) {
            if (bullet.getGlobalBounds().intersects(enemies[i]->getGlobalBounds())) {
                if (enemies[i]->takeDamage()) {
                    delete enemies[i];
                    enemies.erase(enemies.begin() + i);
                    break;
                }
                result = true;
            }
        }
    } else {
        if (bullet.getGlobalBounds().intersects(hero->getGlobalBounds())) {
            if(hero->takeDamage())
                std::cout << "Sei morto";
            result = true;
        }
    }
    return result;
}

/*
void GameEngine::shootUpdate(GameCharacter &character) {
    sf::Vector2f firePosition = character.getPosition();
    bullets.push_back(new Bullet(*bossTexture, firePosition, sf::Vector2f(0, 0), 100, this));
}*/
