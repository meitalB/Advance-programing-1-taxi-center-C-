
#include "Matrix.h"

// Constructor init the matrix.
Matrix::Matrix(int width, int height) : width(width), height(height) {

    for (int i = 0; i < width ; ++i) {
        for (int j = 0; j < height; ++j) {
            arr[i][j] = NodeMatrix(i, j);
            arr[i][j].setParent(NULL);
            this->neighbors(arr[i][j], i, j);

        }
    }
}

//get width
int Matrix::widthGrid() { return width; }

//get height
int Matrix::heightGrid() { return height; }

//update neighbors
void Matrix::neighbors(Node& n, int x , int y){
    if (x > 0) {
        n.addNeighbor(&arr[x - 1][y]);
    }
    if (y < height - 1) {
        n.addNeighbor(&arr[x][y + 1]);
    }
    if (x < width - 1) {
        n.addNeighbor(&arr[x + 1][y]);
    }
    if (y > 0) {
        n.addNeighbor(&arr[x][y - 1]);
    }
}
//get a Node
Node* Matrix::getNode(int x, int y) {
    return &this->arr[x][y];
}

//initialize the matrix
void Matrix::initDistanceForAll(int d) {
    for (int i = 0; i < width ; ++i) {
        for (int j = 0; j < height; ++j) {
            arr[i][j].setDistance(d);
        }
    }
}
