//
// Created by mei on 29/11/16.
//
#include "Point.h"
#include "Person.h"

#ifndef EX2AP_PASSANGER_H
#define EX2AP_PASSANGER_H


class Passenger : public Person{
private:
    Point source;
    Point destination;
public:
    //constructor
    Passenger(int id, int age, STATUS status, Point location, Point sourceNew, Point destinationNew);

    //getters and setters
    Point getSourcePoint();

    //getters and setters
    void setSourcePoint(Point p);

    //getters and setters
    Point getDestinationPoint();

    //getters and setters
    void setDestinationPoint(Point p);

    //produce Random Score
    int produceRandomScore();
};


#endif //EX2AP_PASSANGER_H
