//
// Created by noam on 17/12/16.
//

#ifndef EX2AP_RIDE_H
#define EX2AP_RIDE_H


#include "Trip.h"
#include "persons/Driver.h"
#include "cabs/TaxiCab.h"
#include "Clock.h"

class Ride {
private:
    Point start;
    Point end;
    Trip* trip;
    Driver* driver;
    Clock *clock;
public:

    //constructor
    Ride(Trip* trip, Driver* driver);

    ~Ride();

    // check if the ride is done , if yes-return true, else false
    bool isDone();

    //move the ride one step
    void moveOneStep();

    //move the ride to the end
    void moveToTheEnd();

    //getters and setters
    Point getEndPoint();

    //getters and setters
    Point getStartPoint();

    //getters and setters
    Trip* getTrip();

    //getters and setters
    Driver* getDriver();

    //getters and setters
    Point getDriverLocation();
};


#endif //EX2AP_RIDE_H
