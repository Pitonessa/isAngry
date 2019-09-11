#include <iostream>
#include <cmath>
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
    float height = window.getView().getSize().y * 2 / 3;
    std::vector<MenuItem*> list;
    list.push_back(new MenuItem(MenuItem::START));
    list.push_back(new MenuItem(MenuItem::RECORD));
    list.push_back(new MenuItem(MenuItem::EXIT));
    Menu menu(list, Menu::CENTERED);

    sf::Texture background;
    sf::Texture background2;
    background.loadFromFile("../Res/candy.jpeg");
    background2.loadFromFile("../Res/candy.jepg");

    sf::VertexArray backgroundLayer(sf::Triangles);
    backgroundLayer.append(sf::Vertex(
            sf::Vector2f(-100, height),
            sf::Color::Green
    ));
    backgroundLayer.append(sf::Vertex(
            sf::Vector2f(100, height - 400),
            sf::Color::Green
    ));
    backgroundLayer.append(sf::Vertex(
            sf::Vector2f(200, height),
            sf::Color(30, 150, 80)
    ));

    sf::VertexArray backgroundLayer2(sf::Triangles);
    backgroundLayer2.append(sf::Vertex(
            sf::Vector2f(-50, height),
            sf::Color::Cyan
    ));
    backgroundLayer2.append(sf::Vertex(
            sf::Vector2f(100, height - 150),
            sf::Color(30, 150, 80)
    ));
    backgroundLayer2.append(sf::Vertex(
            sf::Vector2f(250, height),
            sf::Color(30, 150, 80)
    ));

    sf::VertexArray backgroundLayer3(sf::Triangles);
    backgroundLayer3.append(sf::Vertex(
            sf::Vector2f(0, height),
            sf::Color(-100, 80, 30)
    ));
    backgroundLayer3.append(sf::Vertex(
            sf::Vector2f(0, height - 75),
            sf::Color(0, 80, 30)
    ));
    backgroundLayer3.append(sf::Vertex(
            sf::Vector2f(100, height),
            sf::Color(0, 80, 30)
    ));

    sf::VertexArray terrain(sf::Quads);
    terrain.append(sf::Vertex(
            sf::Vector2f(0, height),
            sf::Color(255, 255, 100)
    ));
    terrain.append(sf::Vertex(
            sf::Vector2f(window.getView().getSize().x, height),
            sf::Color(255, 255, 100)
    ));
    terrain.append(sf::Vertex(
            sf::Vector2f(window.getView().getSize().x, window.getView().getSize().y),
            sf::Color(255, 255, 100)
    ));
    terrain.append(sf::Vertex(
            sf::Vector2f(0, window.getView().getSize().y),
            sf::Color(255, 255, 100)
    ));

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
                    float d = window.getView().getSize().x;
                    if (e.key.code == sf::Keyboard::Escape)
                        gameState = 2;
                    else {
                        float a = backgroundLayer[backgroundLayer.getVertexCount() - 1].position.x;
                        //std::cout << std::endl << backgroundLayer3.getVertexCount() << std::endl;
                        if (a < d) {
                            //ADD A MOUNTAIN
                            float pendence = static_cast<float>((rand() % 201) + 200) / 100;
                            float offSet = (backgroundLayer[backgroundLayer.getVertexCount() - 1].position.x -
                                            backgroundLayer[backgroundLayer.getVertexCount() - 2].position.x) / (rand() % 2 + 1);
                            float mHeight = static_cast<float>(rand() % 301) + 300;
                            float start = backgroundLayer[backgroundLayer.getVertexCount() - 1].position.x - offSet;
                            float distance = mHeight / pendence;
                            backgroundLayer.append(sf::Vertex(
                                    sf::Vector2f(start, height),
                                    sf::Color::Green
                            ));
                            backgroundLayer.append(sf::Vertex(
                                    sf::Vector2f(start + distance, height - mHeight),
                                    sf::Color::Green
                            ));
                            backgroundLayer.append(sf::Vertex(
                                    sf::Vector2f(start + 2 * distance, height),
                                    sf::Color::Green
                            ));



                            std::cout << "Montagna aggiunta" << std::endl;
                        }

                        a = backgroundLayer[backgroundLayer2.getVertexCount() - 1].position.x;
                        if(a < d) {
                            float pendence = static_cast<float>((rand() % 101) + 100) / 100;
                            float offSet = (backgroundLayer2[backgroundLayer2.getVertexCount() - 1].position.x -
                                            backgroundLayer2[backgroundLayer2.getVertexCount() - 2].position.x) / (rand() % 3 + 1);
                            float mHeight = static_cast<float>(rand() % 151) + 150;
                            float start = backgroundLayer2[backgroundLayer2.getVertexCount() - 1].position.x - offSet;
                            float distance = mHeight / pendence;
                            backgroundLayer2.append(sf::Vertex(
                                    sf::Vector2f(start, height),
                                    sf::Color(30, 150, 80)
                            ));
                            backgroundLayer2.append(sf::Vertex(
                                    sf::Vector2f(start + distance, height - mHeight),
                                    sf::Color(30, 150, 80)
                            ));
                            backgroundLayer2.append(sf::Vertex(
                                    sf::Vector2f(start + 2 * distance, height),
                                    sf::Color(30, 150, 80)
                            ));
                            std::cout << "Montagna aggiunta" << std::endl;
                        }
                        a = backgroundLayer3[backgroundLayer3.getVertexCount() - 1].position.x;
                        //std::cout << std::endl << a << std::endl;

                        if(a < d) {
                            float pendence = static_cast<float>((rand() % 51) + 50) / 100;
                            float offSet = (backgroundLayer3[backgroundLayer3.getVertexCount() - 1].position.x -
                                            backgroundLayer3[backgroundLayer3.getVertexCount() - 2].position.x) / (rand() % 3 + 1);
                            float mHeight = static_cast<float>(rand() % 51) + 50;
                            float start = backgroundLayer3[backgroundLayer3.getVertexCount() - 1].position.x - offSet;
                            float distance = mHeight / pendence;
                            std::cout << "Pendence: " << pendence << std::endl
                                      << "offset: " << offSet << std::endl
                                      << "mheight: " << mHeight << std::endl
                                      << "start: " << start << std::endl
                                      << "distance: " << distance << std::endl;
                            backgroundLayer3.append(sf::Vertex(
                                    sf::Vector2f(start, height),
                                    sf::Color(0, 80, 30)
                            ));
                            backgroundLayer3.append(sf::Vertex(
                                    sf::Vector2f(start + distance, height - mHeight),
                                    sf::Color(0, 80, 30)
                            ));
                            backgroundLayer3.append(sf::Vertex(
                                    sf::Vector2f(start + 2 * distance, height),
                                    sf::Color(0, 80, 30)
                            ));
                            std::cout << "Montagna 3 aggiunta, posizione finale: " << backgroundLayer3[backgroundLayer3.getVertexCount() -1].position.x << std::endl;
                        }
                    }
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
            window.clear(sf::Color::Black);
            sf::Sprite back(background);
            back.scale(sf::Vector2f(window.getView().getSize().y / background.getSize().y, window.getView().getSize().y / background.getSize().y));
            sf::Sprite back2(background2);
            back2.setOrigin(sf::Vector2f(0, 0));
            back2.setPosition(back.getGlobalBounds().width, 0);
            back2.scale(sf::Vector2f(window.getView().getSize().y / background.getSize().y, window.getView().getSize().y / background.getSize().y));
            window.draw(back);
            window.draw(back2);

        } else {
            window.clear(sf::Color(19, 24, 98));


            window.draw(terrain);
            window.draw(backgroundLayer);
            window.draw(backgroundLayer2);
            window.draw(backgroundLayer3);
        }
        window.display();
    }
    return 0;
}