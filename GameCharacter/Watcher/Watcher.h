//
// Created by mac on 18/09/19.
//

#ifndef ISANGRY_WATCHER_H
#define ISANGRY_WATCHER_H


#include "../GameCharacter.h"



class Watcher: public GameCharacter {
public:
    Watcher(float speed, sf::Texture& Texture, sf::Vector2f position);
    void attack() override;



};


#endif //ISANGRY_WATCHER_H
