
#ifndef NEWEX1_NODEMETRIX_H
#define NEWEX1_NODEMETRIX_H


#include <iosfwd>
#include "Node.h"
#include "Point.h"

class NodeMatrix : public Node {
private:
    Point point ;
public:
    //constracor with no parameters
    NodeMatrix();

    //get the point
    Point getPoint() const;

    //constructor uses int x and y
    NodeMatrix(int x, int y);

    //overloading ==
    bool operator== (const Node &n);

    //print the value
    void printValue(ostream &os) const;
};
//overloading <<
ostream& operator<<(ostream& os, const NodeMatrix& n);



#endif //NEWEX1_NODEMETRIX_H
