//
// Created by mei on 03/12/16.
//

#ifndef EX2AP_TAXICENTER_H
#define EX2AP_TAXICENTER_H


#include "Driver.h"
#include "TaxiCab.h"
#include "Trip.h"

class TaxiCenter {
private:
    std::list<Driver> drivers;
    std::list<TaxiCab> cabs;
    std::list<Trip> trips;
public:
    void answerCall();
    TaxiCab sendTaxi();
};

#endif //EX2AP_TAXICENTER_H
