//
// Created by mei on 03/12/16.
//

#include <iostream>
#include "TaxiCenter.h"

//send a taxi
TaxiCab TaxiCenter::sendTaxi() {
    return TaxiCab(HONDA, RED, 0,0,0);
}

//answer call
void TaxiCenter::answerCall() {
    return;
}

//add a driver to the center
void TaxiCenter::addDriver(Driver d) {
    this->freeDrivers.push_back(d);
}

//add a taxi cab to the center
void TaxiCenter::addTaxiCab(TaxiCab taxi) {
    this->freeCabs.push_back(taxi);
}

//add a trip to the center
void TaxiCenter::addTrip(Trip t) {
    this->freeTrips.push_back(t);
}

//remove a driver to the center
void TaxiCenter::removeDriver(int id) {
    for (vector<Driver>::iterator it = freeDrivers.begin(); it != freeDrivers.end(); ++it) {
        if(it->getId() == id) {
            it = this->freeDrivers.erase(it);
        }
    }
    for (vector<Driver>::iterator it = busyDrivers.begin(); it != busyDrivers.end(); ++it) {
        if(it->getId() == id) {
            it = this->busyDrivers.erase(it);
        }
    }
}

//remove a trip to the center
void TaxiCenter::removeTrip(int id) {
    for (vector<Trip>::iterator it = freeTrips.begin(); it != freeTrips.end(); ++it) {
        if(it->getId() == id) {
            it = this->freeTrips.erase(it);
        }
    }
    for (vector<Trip>::iterator it = busyTrips.begin(); it != busyTrips.end(); ++it) {
        if(it->getId() == id) {
            it = this->busyTrips.erase(it);
        }
    }
}

//get the driver location
Point TaxiCenter::getDriverLocation(int id) {
    for (vector<Driver>::iterator it = freeDrivers.begin(); it != freeDrivers.end(); ++it) {
        if(it->getId() == id) {
            return it->getCurrentLocation();
        }
    }
    for (vector<Driver>::iterator it = busyDrivers.begin(); it != busyDrivers.end(); ++it) {
        if(it->getId() == id) {
            return it->getCurrentLocation();
        }
    }
    return Point(-8,-8);
}

//create a new ride
void TaxiCenter::createRides() {
    unsigned long index = 0;
    for (vector<Driver>::iterator it = freeDrivers.begin(); it != freeDrivers.end(); ++it, ++index) {
        if(freeTrips.size() < 1 ) {
            return;
        }

        busyTrips.push_back(freeTrips[0]);
        freeTrips.erase(freeTrips.begin());

        busyDrivers.push_back(freeDrivers[0]);
        it=freeDrivers.erase(freeDrivers.begin());

        Ride r = Ride(&busyTrips.front(), &busyDrivers.front());
        rides.push_back(r);

    }
}

//move all the rides one step forward
void TaxiCenter::moveAllRidesOneStep() {
    for (vector<Ride>::iterator it = rides.begin(); it != rides.end(); ++it) {
        it->moveOneStep();
    }
}

//move all the rides to the end point
void TaxiCenter::moveAllRidesToTheEnd() {
    while(rides.size() > 0) {
        rides.front().moveToTheEnd();
        busyTrips.erase(busyTrips.begin());
        rides.erase(rides.begin());

        freeDrivers.push_back(busyDrivers[0]);
        busyDrivers.erase(busyDrivers.begin());
    }
}

//get a taxi from the list by vehicle id
TaxiCab TaxiCenter::getTaxi(int idVehicle) {
    int index = 0;
    for (vector<TaxiCab>::iterator it = freeCabs.begin(); it != freeCabs.end(); ++it ,++index) {
        if(it->getId() == idVehicle) {
            return freeCabs[index];
        }
    }
}


