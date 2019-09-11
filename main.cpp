#include <iostream>
#include "SFML/Graphics.hpp"
#include "GUI/Menu/Menu.h"
#include "GameObjects/Star/Star.h"

/**
 * @param gameState indica lo stato del gioco
 * 0 se nel menù principale
 * 1 se nella schermata dei record
 * 2 se in gioco
 * 3 se in pausa
 * usato per discriminare i set di comandi
 *
 * @return
 */

int main() {

    short unsigned int gameState = 0;
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "isAngry");
    std::vector<MenuItem*> list;
    list.push_back(new MenuItem(MenuItem::START));
    list.push_back(new MenuItem(MenuItem::RECORD));
    list.push_back(new MenuItem(MenuItem::EXIT));
    Menu menu(list, Menu::CENTERED);

    std::vector<Star*> stars;
    for (int i = 0; i < 300; i++) {
        float posX = rand() % window.getSize().x;
        float posY = rand() % window.getSize().y * 1.25;
        stars.push_back(new Star(rand() % 5 + 1, 7));
        stars[i]->setPosition(posX, posY);
        stars[i]->setFillColor(sf::Color::White);
    }

    int length = stars.size();

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
                if (gameState == 0) {
                    if ((e.key.code == sf::Keyboard::W) || (e.key.code == sf::Keyboard::Up))
                            menu.backward();
                        if ((e.key.code == sf::Keyboard::S) || (e.key.code == sf::Keyboard::Down))
                            menu.forward();
                        if (e.key.code == sf::Keyboard::Enter) {
                            switch (menu.getAction()) {
                                case MenuItem::TYPE::EXIT:
                                    window.close();
                                    break;
                                case MenuItem::TYPE::RECORD:
                                    gameState = 1;
                                    break;
                                case MenuItem::TYPE::START:
                                    gameState = 2;
                                    break;
                                default:
                                    std::cout << "Pulsante non configurato";
                                    break;
                            }
                        }

                } else if (gameState == 1) {
                    if (e.key.code == sf::Keyboard::RShift)
                        gameState = 0;
                } else if (gameState == 2) {
                    if (e.key.code == sf::Keyboard::RShift)
                        gameState = 0;
                    if (e.key.code == sf::Keyboard::Escape)
                        gameState = 3;
                } else {
                    if (e.key.code == sf::Keyboard::Escape)
                        gameState = 2;
                }
            }
        }
        if (gameState == 0) {
            int counter = 0;
            for (auto i : stars) {
                if ((counter < length * 3 / 4 ) && (static_cast<int> (rand() % 100) < 10))
                    i->updateBrightness();
                else if ((static_cast<int> (rand() % 100) < 40))
                    i->updateBrightness();
                i->updatePosition();
            }
            window.clear(sf::Color(19, 24, 98));
            for (auto j : stars) {
                window.draw(*j);
            }
            menu.draw(window);
        } else if (gameState == 1) {
            window.clear(sf::Color::Red);
        }
        else if (gameState == 2) {
            window.clear(sf::Color::Cyan);
        } else {
            window.clear((sf::Color::Yellow));
        }
        window.display();
    }
    return 0;
}