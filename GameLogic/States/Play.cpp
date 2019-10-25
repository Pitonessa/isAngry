//
// Created by mac on 18/10/19.
//

#include "Play.h"
#include "Pause.h"

Play::Play(GameEngine *gameEngine): Screen(), gameEngine(gameEngine) {
  if(gameEngine->getHero() == nullptr)
      gameEngine->setHero(new Hero(5,sf::Vector2f()));
  if(gameEngine->getEnemies().size()== 0){
      //gameEngine->setEnemies()
  }
  if(gameEngine->getProps().size() == 0){
      //gameEngine->setProps()
  }
  if (gameEngine->getBullet().size() == 0){
      //gameEngine->setBullet()
  }
  gameEngine->setStars(std::vector<Star*>());
  if (gameEngine->getBackground().size()==0){
      //gameEngine->setBackground()
  }

  }


void Play::update() {
    gameEngine->updateWorld();


}

void Play::handleinput(sf::Keyboard::Key key) {
    switch(key){
        case sf::Keyboard::Right:
            gameEngine->moveHero(sf::Vector2f(1,0));

            break;
        case sf::Keyboard::Left:
            gameEngine->moveHero(sf::Vector2f (-1,0));

            break;
        case sf::Keyboard::Space:
            gameEngine->heroJump();

            break;
        case sf::Keyboard::Escape:
            gameEngine->setScreen(new Pause(gameEngine));
            delete this;
            break;
        default:
            break;
    }


}
