//
// Created by noam on 22/11/16.
//

#ifndef NEWEX1_BFS_H
#define NEWEX1_BFS_H


#include "Node.h"
#include "Grid.h"

using namespace std;

class BFS {
public:
    //do BFS algorithm
    std::list<Node*> funcBFS(Node* start, Node* end);
};

#endif //NEWEX1_BFS_H
