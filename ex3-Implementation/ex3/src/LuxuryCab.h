//
// Created by mei on 02/12/16.
//

#ifndef EX2AP_LUXURYCAB_H
#define EX2AP_LUXURYCAB_H
#include "TaxiCab.h"

class LuxuryCab : public TaxiCab {
public:

    //create a new luxury cab
    LuxuryCab(int cabId, int numOfKilometers, int tariff, MANUFACTURER carManufacturer, COLOR color);

};

#endif //EX2AP_LUXURYCAB_H
