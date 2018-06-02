//
// Created by noam on 17/12/16.
//

#include "Ride.h"
#include "core/Point.h"

//move the ride to the end
void Ride::moveToTheEnd() {
    if (clock->getCurrentTime() >= trip->getTimeOfStart()) {
        this->trip->updateLocation(this->end);
        this->driver->updateLocation(this->end);
    }
}

//move the ride one step
void Ride::moveOneStep() {
    for (int i = 0; i < this->driver->getVelocity(); ++i) {
        if (!isDone()) {
            this->trip->moveOneStep();
            this->driver->updateLocation(this->trip->getCurrentPoint());
        }
    }
}

//constructor
Ride::Ride(Trip* trip, Driver* driver)
        : start(trip->getStartPoint()), end(trip->getEndPoint()), driver(driver), trip(trip) {
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
Trip* Ride::getTrip() {
    return this->trip;
}

//getters and setters
Driver* Ride::getDriver() {
    return this->driver;
}
// check if the ride is done , if yes-return true, else false
bool Ride::isDone() {
    return this->end == this->trip->getCurrentPoint();
}
//getters and setters
Point Ride::getDriverLocation() {
    return this->driver->getCurrentLocation();
}

Ride::~Ride() {
    delete this->trip;
}

