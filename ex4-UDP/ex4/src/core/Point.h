#ifndef NEWEX1_POINT_H
#define NEWEX1_POINT_H


#include "Node.h"
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>

class Point {
private:
    int xVal, yVal;

    friend class boost::serialization::access;
    template<class Archive>
    void serialize(Archive& archive, const unsigned int version)
    {
        archive & xVal;
        archive & yVal;
    }
public:
    Point() : xVal(0), yVal(0) {}


    // Constructor uses int x and y values
    Point(int x, int y);

    //constructor uses Point p
    Point(const Point &p);

    //get x
    int x()const;

    //get y
    int y()const;

    //overloading ==
    bool operator== (const Point &p) const;

    //overloading <<
    friend ostream& operator<<(ostream &os, const Point &p);
};



#endif //NEWEX1_POINT_H
