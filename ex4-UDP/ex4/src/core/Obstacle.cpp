//
// Created by noam on 13/12/16.
//

#include "Obstacle.h"
#include "NodeMatrix.h"


//overloading ==
bool Obstacle::operator== (const Node &n) const {
    return  this->getPoint() == ((Obstacle &) n).getPoint();
}

//get the parent of the current node
Node* Obstacle::getParent() {
    return NULL;
}

//set the parent of the current node
void Obstacle::setParent(Node *p) {}

//get the distance of the current node
int Obstacle::getDistance() {
    return -2;
}

//set the distance of the current node
void Obstacle::setDistance(int d) {}

//add a neighbor to the current node
void Obstacle::addNeighbor(Node *n) {}

//overloading <<
ostream& operator<<(ostream &os, const Obstacle &n) {
    n.printValue(os);
    return os;
}

Obstacle::Obstacle(int x, int y) : NodeMatrix(x, y) {}

