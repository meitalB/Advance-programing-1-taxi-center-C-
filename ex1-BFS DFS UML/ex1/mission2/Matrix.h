
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

    //initilaize the matrix
    void initDistanceForAll(int d);

    //get width
    int widthGrid() ;

    // get height
    int heightGrid() ;
};


#endif //NEWEX1_METRIX_H
