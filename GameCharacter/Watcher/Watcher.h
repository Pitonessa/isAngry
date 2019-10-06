//
// Created by mac on 18/09/19.
//

#ifndef ISANGRY_WATCHER_H
#define ISANGRY_WATCHER_H


#include "../GameCharacter.h"



class Watcher : public GameCharacter {
public:
    Watcher(float speed, sf::Vector2f position);
    bool attack() override;
    void animate() override;
    void action(GameCharacter& hero) override;

    static bool loadTexture();


private:
    static sf::Texture* watcherTexture;
    unsigned alpha{255};
    void fadein();
    void fadeout();
    int actualframe{0};




};


#endif //ISANGRY_WATCHER_H
