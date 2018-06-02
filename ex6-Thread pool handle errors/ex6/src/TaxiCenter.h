//
// Created by mei on 03/12/16.
//

#ifndef EX2AP_TAXICENTER_H
#define EX2AP_TAXICENTER_H

#include <vector>
#include <boost/tuple/tuple.hpp>
#include <map>
#include "persons/Driver.h"
#include "cabs/TaxiCab.h"
#include "Trip.h"
#include "Ride.h"
#include "sockets/TcpServer.h"
#include "creators/TripCreator.h"
#include "ThreadPool.h"

class TaxiCenter {
private:
    Clock *clock;
    TcpServer* tcp;
    std::vector<Ride*> rides;
    std::vector<Driver*> freeDrivers;
    std::vector<TaxiCab*> freeCabs;
    std::vector<Trip*> freeTrips;
    std::vector<pthread_t> clientsThreads;
    std::map<int, pair<Trip*, char> > tripByDrivers;
    //std::map<int, pthread_t> tripThreads;
    pthread_mutex_t map_locker;


    struct ClientData {
        int client_socket;
        TaxiCenter* taxiCenter;
    };
public:
    //constructor
    TaxiCenter(Clock *clock, TcpServer* tcp);

    ~TaxiCenter();

    //answer call
    void answerCall();

    //send a taxi
    TaxiCab sendTaxi();

    void addClient();

    //add a driver to the center
    void addDriver(Driver* d);

    //add a taxi cab to the center
    void addTaxiCab(TaxiCab* taxi);

    //get a taxi from the list by vehicle id
    TaxiCab * getTaxi(int idVehicle);

    //add a trip to the center
    void insertTrip(Trip *t);

    //remove a driver to the center
    void removeDriver(int id);

    //remove a trip to the center
    void removeTrip(int id);

    void removeTaxi(int idVehicle);

    //create a new ride
    void createRides();

    //move all the rides one step forward
    void moveAllRidesOneStep();

    //get the driver location
    Point getDriverLocation(int id);

    void clientFunction(int client_socket);

    static void* threadFunction(void* element);
};

#endif //EX2AP_TAXICENTER_H
