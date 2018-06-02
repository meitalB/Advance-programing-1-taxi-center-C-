//
// Created by mei on 29/11/16.
//

#include "Trip.h"
// Constructor all the members
Trip::Trip(unsigned long length, int id, int totalMeters, int numberOfPassengers,
           double tariff, Point start, Point end) :
        currentLocation(0,0), startPoint(0,0), endPoint(0,0){
    this->length = length;
    this->id = id;
    this->totalMeters = totalMeters;
    this->numberOfPassengers = numberOfPassengers;
    this->tariff = tariff;
    this->startPoint = start;
    this->endPoint = end;
    this->currentLocation = start;
}
//getters ang setters
unsigned long Trip::getLength(){
    return this->length;
}
//getters ang setters
void Trip::setLength(unsigned long length){
    this->length = length;
}
//getters ang setters
int Trip::getId(){
    return this->id;
}
//getters ang setters
void Trip::setId(int id){
    this->id = id;
}
//getters ang setters
int Trip::getTotalMeters(){
    return this->totalMeters;
}
//getters ang setters
void Trip::setTotalMeters(int totalMeters){
    this->totalMeters = totalMeters;
}
//getters ang setters
int Trip::getNumberOfPassengers(){
    return this->numberOfPassengers;
}

//getters ang setters
double Trip::getTariff(){
    return this->tariff;
}
//getters ang setters
void Trip::setTariff(double tariff){
    this->tariff = tariff;
}
//getters ang setters
Point Trip::getStartPoint(){
    return this->startPoint;
}
//getters ang setters
Point Trip::getEndPoint(){
    return this->endPoint;
}
//getters ang setters
void Trip::setStartPoint(Point p){
    this->startPoint = p;
}
//getters ang setters
void Trip::setEndPoint(Point p){
    this->endPoint = p;
}
//getters ang setters
Point Trip::getCurrentPoint(){
    return this->currentLocation;
}
//getters ang setters
void Trip::setCurrentPoint(Point p){
    this->currentLocation = p;
}
//update the trip location
void Trip::updateLocation(Point p){
    this->currentLocation = p;
}

void Trip::setNumberOfPassengers(int numberOfPassengers) {
    this->numberOfPassengers = numberOfPassengers;
}