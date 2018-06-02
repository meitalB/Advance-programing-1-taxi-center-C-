//
// Created by mei on 29/11/16.
//

#include "core/Point.h"
#include <boost/serialization/vector.hpp>

#ifndef EX2AP_TRIP_H
#define EX2AP_TRIP_H

class Trip {
private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& archive, const unsigned int version)
    {
        archive & startPoint;
        archive & endPoint;
        archive & currentLocation;
        archive & path;
        archive & length;
        archive & id;
        archive & totalMeters;
        archive & numOfPassengers;
        archive & tariff;
        archive & timeOfStart;
    }

    vector<Point> path;
    unsigned long length;
    int id;
    int totalMeters;
    int numOfPassengers;
    double tariff;
    Point startPoint;
    Point endPoint;
    Point currentLocation;
    int timeOfStart;

public:
    // Constructor
    Trip() : timeOfStart(-1) {};

    // Constructor all the members
    Trip(unsigned long length, int id, int totalMeters, int numberOfPassenger,
         double tariff, Point start, Point end, vector<Point> path, int timeOfStart);

    //move the one step - to the next point.
    void moveOneStep();

    //getters ang setters
    unsigned long getLength();

    //getters ang setters
    void setLength(unsigned long length);

    //getters ang setters
    int getId();

    //getters ang setters
    void setId(int id);

    //getters ang setters
    int getTotalMeters();

    //getters ang setters
    void setTotalMeters(int totalMeters);

    //getters ang setters
    int getNumberOfPassengers();

    //getters ang setters
    void setNumberOfPassengers(int numberOfPassengers);

    //getters ang setters
    double getTariff();

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

    //getters and setters
    int getTimeOfStart();

    //getters and setters
    void setTimeOfStart(int newTimeOfStart);

    //getters ang setters
    Point getCurrentPoint();

    //getters ang setters
    void setCurrentPoint(Point p);

    //update the trip location
   void updateLocation(Point p);

};


#endif //EX2AP_TRIP_H
