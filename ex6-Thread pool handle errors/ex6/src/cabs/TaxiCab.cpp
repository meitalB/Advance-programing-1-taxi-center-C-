//
// Created by mei on 29/11/16.
//

#include "TaxiCab.h"

//constructor
TaxiCab::TaxiCab(MANUFACTURER carManufacturer, COLOR color, int cabId,
                 int numOfKilometers, int tariff, int velocity)
        : Vehicle(carManufacturer, color) {
    this->cabId = cabId;
    this->numberOfKilometers = numOfKilometers;
    this->tariff = tariff;
    this->velocity = velocity;
}

//getters and setters
int TaxiCab::getId(){
    return this->cabId;
}

//getters and setters
void TaxiCab::setId(int id){
    this->cabId = id;
}

//getters and setters
int TaxiCab::getKilometers(){
    return this->numberOfKilometers;
}
//getters and setters
void TaxiCab::setKilometers(int numberOfKilometers){
    this->numberOfKilometers = numberOfKilometers;
}

int TaxiCab::getTariff(){
    return this->tariff;
}

//getters and setters
void TaxiCab::setTariff(int tariff){
    this->tariff = tariff;
}

//getters and setters
int TaxiCab::getVelocity() {
    return this->velocity;
}
