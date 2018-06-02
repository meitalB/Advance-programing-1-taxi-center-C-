//
// Created by noam on 16/12/16.
//

#ifndef EX2AP_MANUOPTIONS_H
#define EX2AP_MANUOPTIONS_H

#include <iostream>
#include "creators/DriverCreator.h"
#include "creators/TripCreator.h"
#include "creators/TaxiCreator.h"
#include "TaxiCenter.h"
#include "core/Grid.h"
#include "Clock.h"
#include "sockets/Udp.h"
#include "core/Matrix.h"
#include "Serialization.h"

class Menu {
private:
    Matrix *grid;
    TaxiCenter *taxiCenter;
    Clock *clock;
    Udp *udp;
public:

    //constructor to a new
    Menu(TaxiCenter *taxiCenter, Matrix* grid, Clock* clock, Udp* udp);

    //run the funcs with input
    void run();

    //create obstacles from the input arguments
    void getObstacles();

    void advance();

    //pass date from server<->client
    void updatesFromClient();

    //insert a new driver from the input arguments
    void expectingDriver();

    //insert a new trip from the input arguments
    void insertTrip();

    //insert a new taxi from the input arguments
    void insertTaxi();

    //get the driver location from the input arguments
    void getDriverLocation();

    // move all the drivers to the next node in the trip
    void moveAllDriversToTheEnd();
};



#endif //EX2AP_MANUOPTIONS_H
