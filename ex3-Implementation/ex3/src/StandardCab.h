//
// Created by mei on 02/12/16.
//

#ifndef EX2AP_STANDARTCAB_H
#define EX2AP_STANDARTCAB_H


#include "TaxiCab.h"


class StandardCab : public TaxiCab {
public:

    //constructor
    StandardCab(int cabId, int numOfKilometers, int tariff, MANUFACTURER carManufacturer, COLOR color);
};

#endif //EX2AP_STANDARTCAB_H
