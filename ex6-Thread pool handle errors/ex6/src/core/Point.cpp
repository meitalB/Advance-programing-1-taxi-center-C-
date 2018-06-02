
#include "Point.h"
#include <iostream>

// Constructor uses int x and y values
Point::Point(long x, long y) : xVal(x), yVal(y) {}
//get x
long Point::x()const { return  this->xVal; }

//get y
long Point::y()const { return  this->yVal; }

//constructor Point uses Point p
Point::Point(const Point &p) {
    this->xVal = p.x();
    this->yVal = p.y();
}


//print the value
ostream& operator<<(ostream &os, const Point &p) {
    os << "(" << p.x() << "," << p.y() << ")\n";
    return os;
}

//overloading ==
bool Point::operator==(const Point &p) const {
    return ((xVal == p.x()) && (yVal == p.y()));
}
