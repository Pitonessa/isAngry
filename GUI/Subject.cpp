//
// Created by Emanuele Casciaro on 04/10/2019.
//

#include "Subject.h"

Subject::~Subject() {
    for (auto i : observerList) delete i;
    observerList.clear();
}

void Subject::attachObserver(Observer *o) {
    observerList.push_back(o);
}

void Subject::detachObserver(Observer *o) {
    for (auto i = 0; i < observerList.size(); i++) {
        if (o == observerList[i]){
            delete(observerList[i]);
            observerList.erase(observerList.begin() + i);
            break;
        }
    }
}