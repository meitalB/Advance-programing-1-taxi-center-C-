//
// Created by mei on 29/11/16.
//
#include "../core/Point.h"
#include "Person.h"

#ifndef EX2AP_PASSANGER_H
#define EX2AP_PASSANGER_H


class Passenger : public Person{
private:
    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& archive, const unsigned int version)
    {
        archive & boost::serialization::base_object<Person>(*this);
        archive & destination;
    }
    Point destination;
public:
    //constructor
    Passenger() : destination(0, 0) {};
    //constructor
    Passenger(int id, unsigned int age, STATUS status, Point location, Point destination);

    //getters and setters
    Point getDestinationPoint();

    //getters and setters
    void setDestinationPoint(Point p);

    //produce Random Score
    int produceRandomScore();
};


#endif //EX2AP_PASSANGER_H
