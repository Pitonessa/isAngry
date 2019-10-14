//
// Created by Emanuele Casciaro on 11/10/2019.
//

#include "Context.h"

Context::Context() {

}

const State* Context::getState() const {
    return state;
}

void Context::setState(State* newState) {
    state = newState;
}