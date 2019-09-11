//
// Created by Emanuele Casciaro on 2019-08-21.
//

#include "Star.h"
#include <iostream>

Star::Star(float radius, int points) : sf::CircleShape(radius, points) {
    brightness = static_cast<int> ((rand() % 50) + 200);
    speed = static_cast<float> ((rand() % 15 + 1))/ 100;
    gloom = brightness % 2 == 0;
    //this->update();
}
void Star::updateBrightness() {
    if (gloom) {
        if (brightness >= 255) {
            gloom = false;
            brightness = 254;
        }
        else brightness++;
    } else {
        if (brightness <= 98) {
            gloom = true;
            brightness = 99  ;
        }
        else brightness--;
    }
    brightness = brightness < 98 ? 98 : brightness;
    this->setFillColor(sf::Color(brightness, brightness, brightness));
}
void Star::updatePosition(float width) {
    sf::Vector2f pos = getPosition();
    if (pos.x > width + 20)
        setPosition(-10, pos.y);
    else setPosition(pos.x + speed, pos.y);
}

bool Star::getGloom() const {
    return gloom;
}