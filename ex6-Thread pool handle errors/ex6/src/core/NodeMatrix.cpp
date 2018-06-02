//
// Created by noam on 22/11/16.
//

#include "NodeMatrix.h"

//constructor with no parameters
NodeMatrix::NodeMatrix() : point(Point(-1, -1)) {
    point = Point(-1,-1);
}

//constructor uses int x and y
NodeMatrix::NodeMatrix(long x, long y) : point(Point(x, y)) {
    this->isObstacle = false;
}

//print the value
void NodeMatrix::printValue(ostream &os) const {
    os << this->point;
}

//overloading <<
ostream& operator<<(ostream &os, const NodeMatrix &n) {
        n.printValue(os);
        return os;
}

//overloading ==
bool NodeMatrix::operator== (const Node &n) const {
    return this->point == ((NodeMatrix &) n).getPoint();
}



// return the point of node.
Point NodeMatrix::getPoint()const {
    return Point(this->point.x(), this->point.y());
}

void NodeMatrix::setIsObstacle(bool x) {
    this->isObstacle = x;
}

int NodeMatrix::getDistance() {
    if (isObstacle) {
        return -2;
    }
    return Node::getDistance();
}

bool NodeMatrix::IsObstacle() {
    return this->isObstacle;
}
