//
// Created by Emanuele Casciaro on 2019-08-21.
//

#ifndef ISANGRY_STAR_H
#define ISANGRY_STAR_H

#include "SFML/Graphics.hpp"
#include "../GameObject.h"

class Star : public sf::CircleShape {

public:
    Star(float radius, int points);
    unsigned short int brightness;
    bool getGloom() const;
    void updateStar();
    static std::vector<Star*> createStars(sf::RenderWindow* renderWindow, int number = 300);

private:
    float speed;
    bool gloom;
    void updateBrightness();
    void updatePosition(float windowWidth = sf::VideoMode::getDesktopMode().width);
};


#endif //ISANGRY_STAR_H
