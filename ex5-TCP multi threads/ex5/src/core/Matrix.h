
#ifndef NEWEX1_METRIX_H
#define NEWEX1_METRIX_H

#include "Node.h"
#include "iostream"
#include "Grid.h"
#include "NodeMatrix.h"
#include "boost/multi_array.hpp"

class Matrix : public Grid {
private:
    unsigned long width, height;
    vector< vector<NodeMatrix *> > arr;
    //update neighbors
    void neighbors(Node* n, int x, int y);

public:
    // Constructor  init the matrix.
    Matrix(unsigned long width , unsigned long height);

    ~Matrix();

    //get a Node
    Node* getNode(int x, int y);

    Point getPoint(Node *n);

    //initialize the matrix
    void initDistanceForAll(int d);
    //add a new obstacle
    void addObstacle(Node* n);
    //remove a new obstacle
    void removeObstacle(Node* n);

    //get width
    unsigned long getWidth() { return width; }

    //get height
    unsigned long getHeight() { return height; }
};


#endif //NEWEX1_METRIX_H