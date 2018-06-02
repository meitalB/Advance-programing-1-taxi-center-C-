//
// Created by mei on 30/12/16.
//

#include "Clock.h"


//return the current time.
int Clock::getCurrentTime() {
    return this->currentTime;
}

//add 'addTime' to the current time
void Clock::addToCurrentTime(int addTime ) {
    this->currentTime += addTime;
}