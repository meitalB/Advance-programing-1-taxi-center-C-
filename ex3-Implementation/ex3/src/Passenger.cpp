//
// Created by mei on 29/11/16.
//

#include <random>
#include "Passenger.h"
//constructor
Passenger::Passenger(int id, int age, STATUS status, Point location, Point sourceNew, Point destinationNew)
        : Person(id, age, status, location), source(sourceNew), destination(destinationNew) {}

//getters and setters
Point Passenger::getSourcePoint(){
    return this->source;
}

//getters and setters
void Passenger::setSourcePoint(Point p){
    this->source = p;
}

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