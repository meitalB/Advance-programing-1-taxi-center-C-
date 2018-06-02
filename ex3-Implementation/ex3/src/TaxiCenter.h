//
// Created by mei on 03/12/16.
//

#ifndef EX2AP_TAXICENTER_H
#define EX2AP_TAXICENTER_H


#include <vector>
#include "Driver.h"
#include "TaxiCab.h"
#include "Trip.h"
#include "Ride.h"

class TaxiCenter {
private:
    std::vector<Ride> rides;
    std::vector<Driver> freeDrivers;
    std::vector<TaxiCab> freeCabs;
    std::vector<Trip> freeTrips;
    std::vector<Driver> busyDrivers;
    std::vector<Trip> busyTrips;
public:
    //answer call
    void answerCall();

    //send a taxi
    TaxiCab sendTaxi();

    //add a driver to the center
    void addDriver(Driver d);

    //add a taxi cab to the center
    void addTaxiCab(TaxiCab taxi);

    //get a taxi from the list by vehicle id
    TaxiCab getTaxi(int idVehicle);

    //add a trip to the center
        void addTrip(Trip t);

    //remove a driver to the center
    void removeDriver(int id);

    //remove a trip to the center
    void removeTrip(int id);

    //create a new ride
    void createRides();

    //move all the rides one step forward
    void moveAllRidesOneStep();

    //move all the rides to the end point
    void moveAllRidesToTheEnd();

    //get the driver location
    Point getDriverLocation(int id);

};

#endif //EX2AP_TAXICENTER_H
