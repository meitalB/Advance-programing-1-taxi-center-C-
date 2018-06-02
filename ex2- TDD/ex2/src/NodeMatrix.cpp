//
// Created by noam on 22/11/16.
//

#include "NodeMatrix.h"

//constracor with no parameters
NodeMatrix::NodeMatrix() : point(Point(-1, -1)) {
    point =Point(-1,-1);
}

//constructor uses int x and y
NodeMatrix::NodeMatrix(int x, int y) : point(Point(x, y)) {}

//print the value
void NodeMatrix::printValue(ostream &os) const {
    os<<this->point;
}

//overloading <<
ostream& operator<<(ostream &os, const NodeMatrix &n) {
        n.printValue(os);
        return os;
}

//overloading ==
bool NodeMatrix::operator==(const Node &n) {
    return this->point == ((NodeMatrix &) n).getPoint();
}

// return the point of node.
Point NodeMatrix::getPoint()const {
    return this->point;
}



