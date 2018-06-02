
#ifndef NEWEX1_GRID_H
#define NEWEX1_GRID_H


#include "Node.h"
#include "BFS.h"

class Grid {
public:
    //virtual func to get the node
    virtual Node* getNode(int x, int y) = 0;

    //virtual initialize the grid
    virtual void initDistanceForAll(int d) = 0;

    //add obstacle
    virtual void addObstacle(Node* n) = 0;

    //remove obstacle
    virtual void removeObstacle(Node* n) = 0;


};


#endif //NEWEX1_GRID_H
