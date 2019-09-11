//
// Created by Emanuele Casciaro on 2019-08-21.
//

#ifndef ISANGRY_STAR_H
#define ISANGRY_STAR_H

#include "SFML/Graphics.hpp"

class Star : public sf::CircleShape {

public:
    Star(float radius, int points);
    unsigned short int brightness;
    void updateBrightness();
    void updatePosition(float windowWidth = sf::VideoMode::getDesktopMode().width);
    bool getGloom() const;
private:
    bool gloom;
    float speed;
};


#endif //ISANGRY_STAR_H
