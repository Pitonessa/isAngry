//
// Created by mac on 18/10/19.
//

#ifndef ISANGRY_SCREEN_H
#define ISANGRY_SCREEN_H


#include <SFML/Graphics.hpp>

class Screen {
public:
    virtual void update() = 0;
    virtual  ~Screen()= default;
  virtual  void handleinput(sf::Keyboard::Key key) = 0;
protected:
    Screen()= default;

};


#endif //ISANGRY_SCREEN_H
