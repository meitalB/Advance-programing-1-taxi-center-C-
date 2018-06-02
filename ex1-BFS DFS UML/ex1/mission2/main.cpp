#include <iostream>
#include "Point.h"
#include "Matrix.h"

int main() {
    int width, height;
    int  startX,startY;
    int endX, endY;
    char temp;
    //input parameters
    std::cin>>width >> temp >> height >> temp >> startX >> temp >> startY >> temp >> endX >> temp >> endY;
    Matrix grid = Matrix(width, height);
    Node* start = grid.getNode(startX, startY);
    Node* end = grid.getNode(endX, endY);
    BFS bfs = BFS();


    // Mark all the vertices as not visit
    grid.initDistanceForAll(INFINITY);
    std::list<Node*> path = bfs.funcBFS(start, end);
    //print BFS path according start and end points
    while (!path.empty()) {
        std::cout<<(*path.front());
        path.pop_front();
    }
    return 0;
}