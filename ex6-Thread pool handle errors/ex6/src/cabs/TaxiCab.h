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
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& archive, const unsigned int version)
    {
        archive & boost::serialization::base_object<Vehicle>(*this);
        archive & cabId;
        archive & numberOfKilometers;
        archive & tariff;
        archive & velocity;
    }
    int cabId;
    int numberOfKilometers;
    int tariff;
    int velocity;

public:
    //constructor
    TaxiCab() : cabId(0), numberOfKilometers(0), tariff(3), velocity(0) {};

    //constructor
    TaxiCab(MANUFACTURER carManufacturer, COLOR color, int cabId,
            int numOfKilometers, int tariff, int velocity);

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

    //getters and setters
    int getVelocity();
};


#endif //EX2AP_TAXICAB_H
