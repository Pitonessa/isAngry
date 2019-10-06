//
// Created by mac on 18/09/19.
//

#ifndef ISANGRY_ARCHER_H
#define ISANGRY_ARCHER_H

#include "../GameCharacter.h"



class Archer : public GameCharacter {
public:
    Archer(float speed, sf::Vector2f position);
    bool attack() override;
    void animate() override;
    void action(GameCharacter& hero) override;
    static bool loadTexture();

private:
    static sf::Texture* archerTexture;


};


#endif //ISANGRY_ARCHER_H
