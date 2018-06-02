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

#include "core/Matrix.h"
#include "Serialization.h"
#include "creators/ThreadCreator.h"
#include "sockets/TcpServer.h"
#include "InputParser.h"

class Menu {
private:
    int guiPort;
    TcpServer* tcp;
    InputParser* inputParser;
    Matrix *grid;
    TaxiCenter *taxiCenter;
    ThreadPool* tripThreadPool;

    bool checkPoint(long x,long y);
    void runOption(int option);
public:

    //constructor to a new
    Menu(TaxiCenter *taxiCenter, Matrix *grid, InputParser *inputParser,
         ThreadPool* tripThreadPool, int guiPort, TcpServer* tcp);

    //run the funcs with input
    void run();

    void moveOneStep();

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