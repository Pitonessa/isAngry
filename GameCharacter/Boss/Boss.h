//
// Created by Emanuele Casciaro on 09/10/2019.
//

#ifndef ISANGRY_BOSS_H
#define ISANGRY_BOSS_H


#include "../Archer/Archer.h"
#include "../Brawler/Brawler.h"
#include "../Watcher/Watcher.h"

class Boss : public Archer, public Brawler, public Watcher {
public:
    Boss(float speed, sf::Vector2f position);

    bool attack() override;
    void animate() override;
    Bullet* action(GameCharacter& hero) override;
    static bool loadTexture();


private:
    static sf::Texture* bossTexture;

};


#endif //ISANGRY_BOSS_H
