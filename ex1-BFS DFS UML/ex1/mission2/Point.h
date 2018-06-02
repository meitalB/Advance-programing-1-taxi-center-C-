#ifndef NEWEX1_POINT_H
#define NEWEX1_POINT_H


#include <iosfwd>
#include "Node.h"

class Point {
private:
    int xVal, yVal;
public:
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
