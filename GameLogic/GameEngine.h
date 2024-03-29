//
// Created by Emanuele Casciaro on 18/09/2019.
//

#ifndef ISANGRY_GAMEENGINE_H
#define ISANGRY_GAMEENGINE_H


#include <iostream>
#include "SFML/Graphics.hpp"
#include "../GameObjects/Bullet/Bullet.h"
#include "../GameCharacter/Hero/Hero.h"
#include "../GUI/Menu/Menu.h"
#include "../GameObjects/Star/Star.h"
#include "../GameCharacter/Factories/GameFactory.h"
#include "States/Screen.h"

//TODO ADD STATE PATTERN

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
    void addEnemy(GameFactory::enemytype type);
    void setHeroPos(float x, float y);
    void heroAttack();
    bool detectCollision(Bullet& bullet);
    sf::RenderWindow& getWindow();
    static float getGravity();
    static float k;
    void setScreen( Screen* screen);


    sf::Texture* backgroundTexture;
    void setHero(Hero* newHero);
    const Hero* getHero() const;
    void setMenu(Menu* newMenu);
    const Menu* getMenu() const;
    void Clear();
    void setStars(std::vector<Star*> newStar);
    Menu* gameMenu;
    void setEnemies(std::vector<GameCharacter*> newEnemies);
    const std::vector<GameObject*> getProps() const;
    void setProps(std::vector<GameObject*> newProps);
    const std::vector<Bullet*> getBullet()const;
    void setBullet(std::vector<Bullet*> newBullet);
    const std::vector<sf::Sprite*> getBackground() const;
    void setBackground(std::vector<sf::Sprite*> newBackground);
    void updateWorld();

    const std::vector<GameCharacter *> &getEnemies() const;


    const std::vector<Star*>getStar() const;
    short int gameState {0};


    void placeEnemy(GameCharacter&enemy, bool isArcher=false);
private:
    sf::RenderWindow* gameWindow;
    Hero* hero;
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
    float groundLevel{961.5};
    Screen* actualScreen;

};


#endif //ISANGRY_GAMEENGINE_H
