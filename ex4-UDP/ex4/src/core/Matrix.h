
#ifndef NEWEX1_METRIX_H
#define NEWEX1_METRIX_H

#include "Node.h"
#include "iostream"
#include "Grid.h"
#include "NodeMatrix.h"



class Matrix : public Grid {
private:
    int width, height;
    NodeMatrix arr[10][10];

    //update neighbors
    void neighbors(Node& n, int x, int y);

public:
    // Constructor  init the matrix.
    Matrix(int width , int height);

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
    int getWidth() { return width; }

    //get height
    int getHeight() { return height; }
};


#endif //NEWEX1_METRIX_H
