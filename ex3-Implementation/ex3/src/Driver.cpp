//
// Created by mei on 29/11/16.
//

#include "Driver.h"

Driver::Driver(Point location, int id, int age, int yearsOfExperience,
               int averageSatisfaction, STATUS status, TaxiCab taxi) : Person(id, age, status, location), taxi(taxi) {
    this->yearsOfExperience = yearsOfExperience;
    this->averageSatisfaction = averageSatisfaction;
}

//getters and setters
int Driver::getYearsOfExperience(){
    return this->yearsOfExperience;
}
//getters and setters
void Driver::setYearsOfExperience(int yearsOfExperience){
    this->yearsOfExperience = yearsOfExperience;
}
//getters and setters
int Driver::getAverageSatisfaction(){
    return this->averageSatisfaction;
}
//getters and setters
void Driver::setAverageSatisfaction(int averageSatisfaction){
    this->averageSatisfaction = averageSatisfaction;
}
