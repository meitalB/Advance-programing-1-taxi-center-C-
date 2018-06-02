//
// Created by mei on 29/11/16.
//

#include "Trip.h"
// Constructor all the members
Trip::Trip(int lengthNew, int rideNew, int totalMetersNew,
     int numberOfPassNew,double tariffnew,
           Point startnew, Point endnew,
           Point currentlocationnew):currentlocation(0,0)
        ,startPoint(0,0),endPoint(0,0){
    length=lengthNew;
    ride=rideNew;
    totalMeters=totalMetersNew;
    numberofPassangers=numberOfPassNew;
    tariff=tariffnew;
    startPoint=startnew;
    endPoint=endnew;
    currentlocation=currentlocationnew;
}
//getters ang setters
int Trip::getlength(){
    return 0;
}
//getters ang setters
void Trip::setLength(int length){

}
//getters ang setters
int Trip::getRide(){
    return 0;
}
//getters ang setters
void Trip::setRide(int ride){

}
//getters ang setters
int Trip::getTotalmeters(){
    return 0;
}
//getters ang setters
void Trip::setTotalMeters(int totalMeters){

}
//getters ang setters
int Trip::getNumberofPassangers(){
    return 0;
}
//getters ang setters
void Trip::setNumberofPassangers(int numberofPassangers){

}
//getters ang setters
double Trip::getTarrif(){
    return 0.0;
}
//getters ang setters
void Trip::setTariff(double tariff){

}
//getters ang setters
Point Trip::getStartPoint(){
    return Point(0,0);
}
//getters ang setters
Point Trip::getEndPoint(){
    return Point(0,0);
}
//getters ang setters
void Trip::setStartPoint(Point p){

}
//getters ang setters
void Trip::setEndPoint(Point p){

}
//getters ang setters
Point Trip::getCurrentPoint(){
    return Point(0,0);
}
//getters ang setters
void Trip::setCurrentPoint(Point p){

}
//update the trip location
void Trip::updateLocation(Point p){

}