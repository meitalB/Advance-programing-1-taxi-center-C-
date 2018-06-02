//
// Created by mei on 29/11/16.
//
#ifndef EX2AP_TAXICAB_H
#define EX2AP_TAXICAB_H

#include <string>
#include "string.h"
#include "Vehicle.h"
using namespace std;

class TaxiCab : public Vehicle {
private:
    int cabId;
    int numberOfKilometers;
    int tariff;
public:
    //constractor
    TaxiCab(MANUFACTURER carManufacturer, COLOR color, int cabId, int numOfKilometers, int tariff);

    //getters and setters
    int getId();

    //getters and setters
    void setId(int id);

    //getters and setters
    int getKilometers();

    //getters and setters
    void setKilometers(int numberOfKilometers);

    //getters and setters
    int getTariff();

    //getters and setters
    void setTariff(int tariff);
};


#endif //EX2AP_TAXICAB_H
