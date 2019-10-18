//
// Created by mac on 18/10/19.
//

#ifndef ISANGRY_SCREEN_H
#define ISANGRY_SCREEN_H


class Screen {
public:
    virtual void update() = 0;
    //virtual void handleInput(...) = 0;
    virtual  ~Screen()= default;

protected:
    Screen()= default;

};


#endif //ISANGRY_SCREEN_H
