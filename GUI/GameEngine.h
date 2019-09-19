//
// Created by Emanuele Casciaro on 18/09/2019.
//

#ifndef ISANGRY_GAMEENGINE_H
#define ISANGRY_GAMEENGINE_H


#include "SFML/Graphics.hpp"
#include "../GameObjects/Bullet/Bullet.h"
#include "../GameCharacter/Hero/Hero.h"
#include "Menu/Menu.h"
#include "../GameObjects/Star/Star.h"
#include <iostream>

class GameEngine {
public:
    enum PAGE {
        MAIN_MENU,
        RECORD_PAGE,
    };
    explicit GameEngine(sf::RenderWindow& mainWindow);
    void drawWorld() const;
    void navigate(sf::Keyboard::Key key);

    sf::Texture* heroTexture;
    sf::Texture* stalkerTexture;
    sf::Texture* brawlerTexture;
    sf::Texture* archerTexture;
    sf::Texture* bossTexture;

    short int gameState {0};
private:
    sf::RenderWindow* gameWindow;
    Hero* hero;
    Menu* gameMenu;
    std::vector<GameCharacter*> enemies;
    std::vector<GameObject*> props;
    std::vector<Bullet*> bullets;
    std::vector<Star*> stars;
    bool loadTextures();

};


#endif //ISANGRY_GAMEENGINE_H
