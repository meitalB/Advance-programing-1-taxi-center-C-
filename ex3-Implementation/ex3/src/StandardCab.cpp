//
// Created by mei on 02/12/16.
//

#include "StandardCab.h"
#include "StandardCab.h"
//constractor
StandardCab::StandardCab(int cabId, int numOfKilometers,
                     int tariff,MANUFACTURER carManufacturer, COLOR color) :
        TaxiCab(carManufacturer, color, cabId, numOfKilometers, tariff) {}
