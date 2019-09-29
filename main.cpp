#include <iostream>
#include <cmath>
#include "SFML/Graphics.hpp"
#include "GUI/Menu/Menu.h"
#include "GameObjects/Star/Star.h"
#include "GameCharacter/Hero/Hero.h"
#include "GameCharacter/Archer/Archer.h"
#include "GameCharacter/Watcher/Watcher.h"
#include "GameCharacter/Brawler/Brawler.h"
#include "GUI/GameEngine.h"
#include "GameCharacter/Factories/GameFactory.h"
#include <thread>

int main() {
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "isAngry");

    auto cascettoEngine = new GameEngine(window);

    sf::Texture background;
    sf::Texture background2;
    background.loadFromFile("../Res/candy2.jpeg");
    background2.loadFromFile("../Res/candy3.jpeg");

    while (window.isOpen()) {

        sf::Event e;

        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed)
                window.close();
            if (e.type == sf::Event::Resized){
                sf::Vector2u size = window.getSize();
                window.setView(sf::View(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y)));
            }
            if (e.type == sf::Event::KeyPressed) {
                if (cascettoEngine->gameState == 0) {
                    cascettoEngine->navigate(e.key.code);
                } else if (cascettoEngine->gameState == 1) {
                    if (e.key.code == sf::Keyboard::RShift)
                        cascettoEngine->gameState = 0;
                } else if (cascettoEngine->gameState == 2) {
                    std::vector<sf::Vector2f> dir;
                    if (e.key.code == sf::Keyboard::RShift)
                        cascettoEngine->gameState = 0;
                    if (e.key.code == sf::Keyboard::Escape)
                        cascettoEngine->gameState = 3;
                    if (e.key.code == sf::Keyboard::N)
                        GameFactory::createEnemy(*cascettoEngine);
                    if (e.key.code == sf::Keyboard::R)
                        cascettoEngine->setHeroPos(window.getView().getSize().x / 2, window.getView().getSize().y / 2);
                } else {
                    float d = window.getView().getSize().x;
                    if (e.key.code == sf::Keyboard::Escape)
                        cascettoEngine->gameState = 2;

                }
            }
        }
        if(cascettoEngine->gameState == 2) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                cascettoEngine->moveHero(sf::Vector2f(0, -1));
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                cascettoEngine->moveHero(sf::Vector2f(0, 1));
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                cascettoEngine->moveHero(sf::Vector2f(-1, 0));
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                cascettoEngine->moveHero(sf::Vector2f(1, 0));
        }
        if (cascettoEngine->gameState == 0) {
            window.clear(sf::Color(19, 24, 98));
            cascettoEngine->drawWorld();
        } else if (cascettoEngine->gameState == 1) {
            window.clear(sf::Color::Red);
        }
        else if (cascettoEngine->gameState == 2) {
            window.clear(sf::Color::Black);
            cascettoEngine->drawWorld();
        } else {
            window.clear(sf::Color(19, 24, 98));
        }
        window.display();
    }
    return 0;
}