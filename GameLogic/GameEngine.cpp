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
#include "../GameCharacter/Boss/Boss.h"

float GameEngine::k = 0;

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
    groundLevel = (7.98f / 11.85f) * background[0]->getGlobalBounds().height;
    /*props.push_back(new Sweet(sf::Vector2f(2000, 1000)));
    props[0]->scale(0.33, 0.33);*/
    //enemies.push_back(new Brawler(5, sf::Vector2f(1000, 300)));

    k = 0.5f/9.0f * gameWindow->getView().getSize().y;

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
        Bullet::loadTexture() &&
        Boss::loadTexture();
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
                    float heroX = hero->getPosition().x;
                    for (auto enemy : enemies) {
                        auto bullet = enemy->action(*hero);
                        if(bullet != nullptr)
                            bullets.push_back(bullet);
                        enemy->move(sf::Vector2f(0, 1));
                        enemy->animate();
                        enemy->fixHeight(groundLevel);
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
                /*case 3:
                    //PAUSE
                    gameWindow->draw(*hero);
                    for (auto enemy : enemies)
                        gameWindow->draw(*enemy);
                    for (auto prop : props)
                        gameWindow->draw(*prop);
                    for (auto bullet : bullets) {
                        gameWindow->draw(*bullet); }
                    break;*/
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
    hero->fixHeight(groundLevel);
}

void GameEngine::addEnemy(GameFactory::enemytype type) {
    GameCharacter* enemy = GameFactory::createEnemy(type);
    placeEnemy(*enemy, type == GameFactory::ARCHER);
    enemies.push_back(enemy);
}

void GameEngine::setHeroPos(float x, float y) {
    hero->setPosition(x, y);
}

 sf::RenderWindow& GameEngine::getWindow() {
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
    float position=hero->getPosition().y;
    float h= hero->getGlobalBounds().height;
    if(position + h >= groundLevel)
        hero->jump();

}

void GameEngine::heroAttack() {
    if(hero->attack()) {
        bullets.push_back(new Bullet(hero->getPosition(), sf::Vector2f(2000 * (hero->getDirection()), 0), 0, true));
    }

}

bool GameEngine::detectCollision(Bullet &bullet) {
    bool result = false;
    if(bullet.isFriendly()) {
        for (int i = 0; i < enemies.size() && !result; i++) {
            if (bullet.getGlobalBounds().intersects(enemies[i]->getGlobalBounds())) {
                if (enemies[i]->takeDamage()) {
                    delete enemies[i];
                    enemies.erase(enemies.begin() + i);
                }
                result = true;
            }
        }
    } else {
        if (bullet.getGlobalBounds().intersects(hero->getGlobalBounds())) {
            if(hero->takeDamage())
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

float GameEngine::getGravity() {
    return k;
}

void GameEngine::placeEnemy(GameCharacter&enemy, bool isArcher) {
    sf::Vector2f position(gameWindow->getView().getCenter());
    position.x -= gameWindow->getView().getSize().x/2;
    float offset = (rand() % gameWindow->getSize().x);

    if(isArcher){

    }
    else{
        position.y = groundLevel - enemy.getGlobalBounds().height;
    }
    enemy.setPosition(position.x + offset, position.y);
}

 const Hero *GameEngine::getHero() const {
    return hero;
}

void GameEngine::setHero(Hero *newHero) {
    if(hero!= nullptr)
    delete hero;
    hero = newHero;

}

void GameEngine::setMenu(Menu *newMenu) {
    if(gameMenu!= nullptr)
        delete gameMenu;
    gameMenu = newMenu;

}

const Menu *GameEngine::getMenu() const {
    return gameMenu;
}

void GameEngine::Clear() {
    setHero(nullptr);
    for(auto i : enemies) delete i;
    enemies.clear();
    for(auto i : props) delete i;
    props.clear();
    for(auto i : bullets) delete i;
    bullets.clear();
    for(auto i : background) delete i;
    background.clear();
}

void GameEngine::setStars(std::vector<Star *> newStar) {
    for(auto i: stars) delete i;
    stars.clear();
    stars = newStar;

}

const std::vector<Star *> GameEngine::getStar() const {
    return stars;
}

void GameEngine::setScreen(Screen *newscreen) {
    if(actualScreen != nullptr)
        delete actualScreen;
    actualScreen=newscreen;


}

const std::vector<GameCharacter *> &GameEngine::getEnemies() const {
    return enemies;
}

void GameEngine::setEnemies(std::vector<GameCharacter *> newEnemies) {
    if(enemies.size() != 0)
        for(auto i : enemies)
            delete i;
        enemies.clear();
        enemies=newEnemies;


}

void GameEngine::setProps(std::vector<GameObject *> newProps) {
    if(props.size() != 0)
        for(auto i : props)
            delete i;
        props.clear();
        props=newProps;

}

const std::vector<GameObject *> GameEngine::getProps() const {
    return std::vector<GameObject *>();
}

const std::vector<Bullet *> GameEngine::getBullet() const {
    return std::vector<Bullet *>();
}

void GameEngine::setBullet(std::vector<Bullet *> newBullet) {
    if(bullets.size() != 0)
        for(auto i : bullets)
            delete i;
        bullets.clear();
        bullets=newBullet;

}

const std::vector<sf::Sprite *> GameEngine::getBackground() const {
    return std::vector<sf::Sprite *>();
}

void GameEngine::setBackground(std::vector<sf::Sprite *> newBackground) {
    for(auto i: background)
        delete i;
    background.clear();
    background=newBackground;

}

void GameEngine::updateWorld() {
    for (auto enemy : enemies) {
        auto bullet = enemy->action(*hero);
        if(bullet != nullptr)
            bullets.push_back(bullet);
        enemy->move(sf::Vector2f(0, 1));
        enemy->animate();
        enemy->fixHeight(groundLevel);

    }

    for (auto prop : props){
        prop->update();

    }

    for (unsigned long i = 0; i < bullets.size(); i++) {
        bullets[i]->update();
        if (bullets[i]->isOut(gameWindow->getView(), 1000) || detectCollision(*bullets[i])) {
            delete bullets[i];
            bullets.erase(bullets.begin() + i);
        }


    }
    moveView();


}
