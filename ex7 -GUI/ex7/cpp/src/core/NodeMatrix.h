
#ifndef NEWEX1_NODEMETRIX_H
#define NEWEX1_NODEMETRIX_H


#include <iosfwd>
#include "Node.h"
#include "Point.h"

class NodeMatrix : public Node {
protected:
    Point point ;
    bool isObstacle;
public:
    //constructor with no parameters
    NodeMatrix();

    //get the point
    Point getPoint() const;

    //constructor uses int x and y
    NodeMatrix(long x, long y);

    void setIsObstacle(bool x);

    bool IsObstacle();

    int getDistance();


    //overloading ==
    bool operator== (const Node &n) const ;

    //print the value
    void printValue(ostream &os) const;

//    virtual ~NodeMatrix();

    //overloading <<
    friend ostream& operator<<(ostream& os, const NodeMatrix& n);
};




#endif //NEWEX1_NODEMETRIX_H
