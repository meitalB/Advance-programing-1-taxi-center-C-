//
// Created by noam on 13/12/16.
//

#ifndef EX2AP_OBSTACLE_H
#define EX2AP_OBSTACLE_H


#include "Point.h"
#include "NodeMatrix.h"


class Obstacle : public NodeMatrix {
public:

    Obstacle(int x, int y);
    //get the parent of the current node
    Node* getParent();

    //set the parent of the current node
    void setParent(Node *p);

    //get the distance of the current node
    int getDistance();

    //set the distance of the current node
    void setDistance(int d);

    //add a neighbor to the current node
    void addNeighbor(Node *n);

    //overloading ==
    bool operator== (const Node &n) const;

    //overloading <<
    friend ostream& operator<<(ostream& os, const Obstacle& n);
};


#endif //EX2AP_OBSTACLE_H
