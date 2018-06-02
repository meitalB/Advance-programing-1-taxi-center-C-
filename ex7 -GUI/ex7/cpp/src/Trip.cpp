//
// Created by mei on 29/11/16.
//

#include "Trip.h"

Trip::Trip(int id, int totalMeters, int numberOfPassengers, double tariff, Point* start, Point* end,
           int timeOfStart) : currentLocation(start), startPoint(start), endPoint(end){
    this->id = id;
    this->totalMeters = totalMeters;
    this->numOfPassengers = numberOfPassengers;
    this->tariff = tariff;
    this->timeOfStart = timeOfStart;
    this->path = NULL;
}

// Constructor all the members
Trip::Trip(unsigned long length, int id, int totalMeters, int numberOfPassengers,
           double tariff, Point* start, Point* end, vector<Point*>* path, int timeOfStart) : path(path) {
    Trip(id ,totalMeters, numberOfPassengers, tariff, start, end, timeOfStart);
    this->length = length;
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
    return this->numOfPassengers;
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
    return *(this->startPoint);
}
//getters ang setters
Point Trip::getEndPoint(){
    return *(this->endPoint);
}
//getters ang setters
void Trip::setStartPoint(Point* p){
    this->startPoint = p;
}
//getters ang setters
void Trip::setEndPoint(Point* p){
    this->endPoint = p;
}
//getters ang setters
Point Trip::getCurrentPoint(){
    return *(this->currentLocation);
}

//update the trip location
void Trip::updateLocation(Point* p){
    this->currentLocation = p;
}

//getters and setters
void Trip::setNumberOfPassengers(int numberOfPassengers) {
    this->numOfPassengers = numberOfPassengers;
}


//getters and setters
int Trip::getTimeOfStart(){
    return  this->timeOfStart;
}
//getters and setters
void Trip::setTimeOfStart(int newTimeOfStart){
    this->timeOfStart = newTimeOfStart;
}

//move one step forward
void Trip::moveOneStep() {
    delete (this->path->front());
    this->path->erase(this->path->begin());
    this->updateLocation(this->path->front());
}

//getters ang setters
void Trip::setPath(std::vector<Point*>* pathPoints){
    this->path = pathPoints;
    setLength(this->path->size());
}
//getters ang setters
bool Trip::hasPath(){
    return this->path != NULL;
}

Trip::~Trip() {
    delete this->startPoint;
    delete this->endPoint;
    if (this->path != NULL) {
        for (int i = 0; i < path->size(); ++i) {
            delete (*path)[i];
        }
        delete this->path;
    }
}
