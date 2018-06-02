//
// Created by mei on 30/12/16.
//
#include <boost/serialization/list.hpp>
#ifndef TAXI_CENTER_CLOCK_H
#define TAXI_CENTER_CLOCK_H


class Clock {
private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& archive, const unsigned int version)
    {
        archive & currentTime;
    }
    int currentTime;
public:
    //constructor -init
    Clock() : currentTime(0) {};

    //return the current time.
    int getCurrentTime();

    //add 'addTime' to the current time
    void addToCurrentTime(int addTime);
};


#endif //TAXI_CENTER_CLOCK_H
