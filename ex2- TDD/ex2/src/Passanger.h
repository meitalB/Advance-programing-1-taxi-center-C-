//
// Created by mei on 29/11/16.
//
#include "Point.h"
#include "Person.h"

#ifndef EX2AP_PASSANGER_H
#define EX2AP_PASSANGER_H


class Passanger : public Person{
private:
    Point source;
    Point destanation;
public:
    //constructor
    Passanger(Point sourceNew,Point destanetionNew);
    //getters and setters
    Point getSourcePoint();
    //getters and setters
    void setSourcePoint(Point p);
    //getters and setters
    Point getDestenationPoint();
    //getters and setters
    void setDestenationPoint(Point p);
    //produce Random Score
    int produceRandomScore();
};


#endif //EX2AP_PASSANGER_H
