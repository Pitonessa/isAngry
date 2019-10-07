//
// Created by Emanuele Casciaro on 18/09/2019.
//

#ifndef ISANGRY_GAMEENGINE_H
#define ISANGRY_GAMEENGINE_H


#include <iostream>
#include "SFML/Graphics.hpp"
#include "../GameObjects/Bullet/Bullet.h"
#include "../GameCharacter/Hero/Hero.h"
#include "Menu/Menu.h"
#include "../GameObjects/Star/Star.h"

class GameEngine {
public:

    enum PAGE {
        MAIN_MENU,
        RECORD_PAGE,
    };
    explicit GameEngine(sf::RenderWindow& mainWindow);
    void drawWorld();
    void navigate(sf::Keyboard::Key key);
    void heroJump();
    void moveHero(sf::Vector2f direction);
    void addEnemy(GameCharacter& enemy);
    void setHeroPos(float x, float y);
    void heroAttack();
    bool detectCollision(Bullet& bullet);
    const sf::RenderWindow& getWindow();
    static float getGravity();
    static float k;

    sf::Texture* backgroundTexture;

    short int gameState {0};


private:
    sf::RenderWindow* gameWindow;
    Hero* hero;
    Menu* gameMenu;
    std::vector<GameCharacter*> enemies;
    std::vector<GameObject*> props;
    std::vector<Bullet*> bullets;
    std::vector<Star*> stars;
    std::vector<sf::Sprite*> background;
    bool loadTextures();
    void moveView();
    void restartClock();
    float gameSpeed;
    sf::Clock gameClock;

};


#endif //ISANGRY_GAMEENGINE_H
