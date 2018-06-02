//
// Created by mei on 29/11/16.
//
#include "Point.h"
#ifndef EX2AP_TRIP_H
#define EX2AP_TRIP_H


class Trip {
private:
    int length;
    int ride;
    int totalMeters;
    int numberofPassangers;
    double tariff;
    Point startPoint;
    Point endPoint;
    Point currentlocation;
public:
    // Constructor all the members
    Trip(int lengthNew, int rideNew, int totalMetersNew,
           int numberOfPassNew,
         double tariffnew, Point startnew, Point endnew,
         Point currentlocationnew);
    //getters ang setters
    int getlength();
    //getters ang setters
    void setLength(int length);
    //getters ang setters
    int getRide();
    //getters ang setters
    void setRide(int ride);
    //getters ang setters
    int getTotalmeters();
    //getters ang setters
    void setTotalMeters(int totalMeters);
    //getters ang setters
    int getNumberofPassangers();
    //getters ang setters
    void setNumberofPassangers(int numberofPassangers);
    //getters ang setters
    double getTarrif();
    //getters ang setters
    void setTariff(double tariff);
    //getters ang setters
    Point getStartPoint();
    //getters ang setters
    Point getEndPoint();
    //getters ang setters
    void setStartPoint(Point p);
    //getters ang setters
    void setEndPoint(Point p);
    //getters ang setters
    Point getCurrentPoint();
    //getters ang setters
    void setCurrentPoint(Point p);
    //update the trip location
   void updateLocation(Point p);

};


#endif //EX2AP_TRIP_H
