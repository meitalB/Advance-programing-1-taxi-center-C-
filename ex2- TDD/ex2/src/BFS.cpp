

#include <iostream>
#include "BFS.h"
//do BFS algorithm
std::list<Node*> BFS::funcBFS(Node* start, Node* end) {
    std::list<Node*> path;
    Node* p;
    // Create a queue for BFS
    std::list<Node*> queue;
    std::list<Node*> neighbors ;
    // enqueue the start node.
    queue.push_back(start);
    start->setDistance(0);
    start->setParent(NULL);
    while (!queue.empty()) {
        // Dequeue a vertex from queue and print it
        start = queue.front();
//        start->printValue();
        //if we get to the destination
        if (start == end) {
            path.push_front(start);
            p = start->getParent();
            while (p != NULL) {
                path.push_front(p);
                p = p->getParent();
            }
            break;
        }


        // Get all adjacent vertices of the dequeue vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        neighbors = start->getNeighbors();
        while (!neighbors.empty()) {
            if (neighbors.front()->getDistance() == -1) {
                neighbors.front()->setDistance(start->getDistance() + 1);
                neighbors.front()->setParent(start);
                queue.push_back(neighbors.front());
            }
            neighbors.pop_front();
        }

        queue.pop_front();
    }
    return path;
}
