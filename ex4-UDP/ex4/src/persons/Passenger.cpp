//
// Created by mei on 29/11/16.
//

#include <random>
#include "Passenger.h"
//constructor
Passenger::Passenger(int id, unsigned int age, STATUS status, Point location, Point destination)
        : Person(id, age, status, location), destination(destination) {}

//getters and setters
Point Passenger::getDestinationPoint(){
    return this->destination;
}

//getters and setters
void Passenger::setDestinationPoint(Point p){
    this->destination = p;
}

//get random score
int Passenger::produceRandomScore(){
    
    return rand() % 5 + 1;
}