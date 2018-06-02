//
// Created by noam on 12/12/16.
//

#include "Vehicle.h"
//constractor
Vehicle::Vehicle(MANUFACTURER carManufacturer, COLOR c) {
    this->manu = carManufacturer;
    this->c = c;
}

//get the MANUFACTURER of the Vehicle
MANUFACTURER Vehicle::getCarManufacturer() {
    return this->manu;
}

//get the COLOR of the Vehicle
COLOR Vehicle::getColor() {
    return this->c;
}
