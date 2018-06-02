//
// Created by mei on 02/12/16.
//

#include "LuxuryCab.h"

//create a new luxury cab
LuxuryCab::LuxuryCab(int cabId, int numOfKilometers,
                     int tariff,MANUFACTURER carManufacturer, COLOR color) :
        TaxiCab(carManufacturer, color, cabId, numOfKilometers, tariff) {}
