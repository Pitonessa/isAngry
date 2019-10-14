//
// Created by mac on 18/09/19.
//

#ifndef ISANGRY_ARCHER_H
#define ISANGRY_ARCHER_H

#include "../GameCharacter.h"



class Archer : virtual public GameCharacter {
public:
    Archer(float speed, sf::Vector2f position);
    bool attack() override;
    void animate() override;
    Bullet* action(GameCharacter& hero) override;
    static bool loadTexture();

private:
    static sf::Texture* archerTexture;
    static int bulletSpeed;


};


#endif //ISANGRY_ARCHER_H
