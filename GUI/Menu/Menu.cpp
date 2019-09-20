//
// Created by Emanuele Casciaro on 2019-08-20.
//

#include <iostream>
#include "Menu.h"

MenuItem::MenuItem(MenuItem::TYPE type) : type(type){
    std::string btnText;
    switch (type) {
        case MenuItem::TYPE::START:
            btnText = "Gioca";
            break;
        case MenuItem::TYPE::RECORD:
            btnText = "Record";
            break;
        case MenuItem::TYPE::EXIT:
            btnText = "Chiudi gioco";
            break;
        case MenuItem::TYPE::QUIT:
            btnText = "Menu principale";
            break;
        case MenuItem::TYPE::RESUME:
            btnText = "Riprendi";
            break;
        case MenuItem::TYPE::SCORE:
            btnText = "Punteggio attuale";
            //TODO CREA OBSERVER PUNTEGGIO
            break;
        case MenuItem::TYPE::INFO:
            btnText = "Informazioni giocatore";
            //TODO CREA OBSERVER STATISTICHE
            break;
        default:
            std::cerr << "Oggetto sbagliato";
    }
    this->setString(btnText);
}

const MenuItem::TYPE& MenuItem::getType() const {
    return type;
}

Menu::Menu(Menu::STYLE style) : style(style){
    if(style == Menu::STYLE::MAIN) {
        itemList.push_back(new MenuItem(MenuItem::TYPE::START));
        itemList.push_back(new MenuItem(MenuItem::TYPE::RECORD));
        itemList.push_back(new MenuItem(MenuItem::TYPE::EXIT));
        itemList[active]->setFillColor(sf::Color::Red);
        count = 3;
    } else if (style == Menu::STYLE::TOP) {
        itemList.push_back(new MenuItem(MenuItem::TYPE::SCORE));
        itemList.push_back(new MenuItem(MenuItem::TYPE::INFO));
        count = 2;
    } else if (style == Menu::STYLE::CENTERED) {
        itemList.push_back(new MenuItem(MenuItem::TYPE::RESUME));
        itemList.push_back(new MenuItem(MenuItem::TYPE::QUIT));
        itemList[active]->setFillColor(sf::Color::Red);
        count = 2;
    } else std::cerr << "Meni non definto";
}

Menu::~Menu() {
    for(auto i : itemList)
        delete i;
    itemList.clear();
}

void Menu::draw(sf::RenderWindow& window) {
    sf::View actualView = window.getView();
    sf::Vector2f origin, dim, pos;
    dim = actualView.getSize();
    origin = actualView.getCenter();
    origin.x -= dim.x / 2;
    origin.y -= dim.y / 2;

    sf::Font font;
    if (!font.loadFromFile("../Res/font/mainFont.otf"))
        std::cerr << "Font non trovato";

    float step = dim.x / count;

    if (style == STYLE::MAIN) {
        int height = count * (64 + 8);
        pos = actualView.getCenter();
        pos.y -= height / 2;
        for (auto i : itemList) {
            i->setCharacterSize(64);
            i->setFont(font);
            sf::FloatRect s = i->getGlobalBounds();
            i->setPosition(pos.x, pos.y);
            i->setOrigin(s.width / 2 , s.height / 2);
            pos.y += 72;
            window.draw(*i);
        }
    } else if (style == STYLE::TOP) {
        pos.y = origin.y + 10;
        pos.x = origin.x + 10;
        for (auto i : itemList) {
            i->setPosition(pos);
            i->setFont(font);
            i->setCharacterSize(64);
            float size = i->getGlobalBounds().width;
            pos.x += size + 60;
            window.draw(*i);
        }
    } else if (style == STYLE::CENTERED) {
        int height = count * (64 + 8);
        pos = actualView.getCenter();
        pos.y -= height / 2;
        for (auto i : itemList) {
            i->setCharacterSize(64);
            i->setFont(font);
            sf::FloatRect s = i->getGlobalBounds();
            i->setPosition(pos.x, pos.y);
            i->setOrigin(s.width / 2 , s.height / 2);
            pos.y += 72;
            window.draw(*i);
        }
        //...
    }
}

void Menu::forward() {
    itemList[active]->setFillColor(sf::Color::White);
    if (active >= count - 1)
        active = 0;
    else active++;
    itemList[active]->setFillColor(sf::Color::Red);
}
void Menu::backward() {
    itemList[active]->setFillColor(sf::Color::White);
    if (active == 0)
        active = count - 1;
    else active--;
    itemList[active]->setFillColor(sf::Color::Red);
}
const Menu::STYLE& Menu::getStyle() const {
    return style;
}
const MenuItem::TYPE& Menu::getAction() const {
    return itemList[active]->getType();
}
