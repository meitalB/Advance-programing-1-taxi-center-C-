
#ifndef NEWEX1_GRID_H
#define NEWEX1_GRID_H


#include "Node.h"
#include "BFS.h"

class Grid {
public:
    //virtual func to get the node
    virtual Node* getNode(int x, int y) = 0;
    //virtual initilaze the grid
    virtual void initDistanceForAll(int d) = 0;
};


#endif //NEWEX1_GRID_H
