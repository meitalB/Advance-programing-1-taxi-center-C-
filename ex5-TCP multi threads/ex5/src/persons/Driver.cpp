//
// Created by mei and noam on 29/11/16.
//

#include "Driver.h"
// constructor
Driver::Driver(Point location, int id, unsigned int age, unsigned int yearsOfExperience,
               int vehicleId, STATUS status)
        : Person(id, age, status, location), taxiCab() {
    this->yearsOfExperience = yearsOfExperience;
    this->vehicleId = vehicleId;
    this->averageSatisfaction = 0;
    this->numberOfVotes = 0;
    this->totalPoints = 0;
}

//getters and setters
int Driver::getYearsOfExperience(){
    return this->yearsOfExperience;
}
//getters and setters
void Driver::setYearsOfExperience(unsigned yearsOfExperience) {
    this->yearsOfExperience = yearsOfExperience;
}
//getters and setters
unsigned int Driver::getAverageSatisfaction() {
    return this->averageSatisfaction;
}
//getters and setters
void Driver::setTaxiCab(TaxiCab* taxi) {
    this->taxiCab = taxi;
}
//getters and setters
TaxiCab* Driver::getTaxiCab() {
    return this->taxiCab;
}
//getters and setters
void Driver::setVehicleId(int vehicleId) {
    this->vehicleId = vehicleId;
}
//getters and setters
int Driver::getVehicleId() {
    return  this->vehicleId;
}
//update points of driver and average of votes to the driver
void Driver::rateDriver(unsigned int points) {
    this->totalPoints += points;
    this->numberOfVotes++;
    this->averageSatisfaction = totalPoints / numberOfVotes;
}
//getters and setters
int Driver::getVelocity() {
    if (taxiCab != NULL){
        return this->taxiCab->getVelocity();
    }
    return 0;
}

Driver::~Driver() {
    if (taxiCab != NULL) {
        delete taxiCab;
    }
}


