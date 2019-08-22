//
// Created by Emanuele Casciaro on 2019-08-21.
//

#include "Star.h"
#include <iostream>

Star::Star(float radius, int points) : sf::CircleShape(radius, points) {
    brightness = static_cast<int> ((rand() % 50) + 200);
    std::cout << brightness << std::endl;
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
        if (brightness <= 0) {
            gloom = true;
            brightness = 1;
        }
        else brightness--;
    }
    this->setFillColor(sf::Color(
            brightness < 79 ? 79 : brightness,
            brightness < 9 ? 9 : brightness,
            brightness < 150 ? 150 : brightness)
            );
}
void Star::updatePosition(float width) {
    sf::Vector2f pos = getPosition();
    if (pos.x > width + 20)
        setPosition(-10, pos.y);
    else setPosition(pos.x + 0.15f, pos.y);
}