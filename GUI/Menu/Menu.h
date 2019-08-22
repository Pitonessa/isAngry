//
// Created by Emanuele Casciaro on 2019-08-20.
//

#ifndef ISANGRY_MENU_H
#define ISANGRY_MENU_H

#include "SFML/Graphics.hpp"

class MenuItem : public sf::Text {
public:
    enum TYPE {
        START,
        RECORD,
        EXIT,
        RESUME,
        QUIT,
        SCORE,
        INFO
    };
    explicit MenuItem(MenuItem::TYPE type);
    const TYPE& getType() const;

private:
    TYPE type;
};

class Menu {
public:
    enum STYLE {
        CENTERED,
        TOP
    };
    Menu(std::vector<MenuItem*>& list, STYLE style);
    void draw(sf::RenderWindow& window);
    void forward();
    void backward();
    const MenuItem::TYPE& getAction() const;
    const STYLE& getStyle() const;
private:
    int active {0};
    int count;
    std::vector<MenuItem*> itemList;
    STYLE style;
};


#endif //ISANGRY_MENU_H
