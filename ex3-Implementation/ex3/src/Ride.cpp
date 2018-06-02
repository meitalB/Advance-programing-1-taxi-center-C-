//
// Created by noam on 17/12/16.
//

#include "Ride.h"
//move the ride to the end
void Ride::moveToTheEnd() {
    this->trip->updateLocation(this->end);
    this->driver->updateLocation(this->end);
}

//move the ride one step
void Ride::moveOneStep() {
    return;
}

//constructor
Ride::Ride(Trip *trip, Driver* driver) : start(trip->getStartPoint()), end(trip->getEndPoint()){
    this->driver = driver;
    this->trip = trip;
}

//getters and setters
Point Ride::getEndPoint() {
    return this->end;
}

//getters and setters
Point Ride::getStartPoint() {
    return this->start;
}

//getters and setters
Trip *Ride::getTrip() {
    return this->trip;
}

//getters and setters
Driver *Ride::getDriver() {
    return this->driver;
}

