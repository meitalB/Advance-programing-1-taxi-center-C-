//
// Created by noam on 16/12/16.
//

#include "TripCreator.h"
//help to craete a trip
Trip createTrip(Matrix grid, int id, int xStart, int yStart,
                int xEnd, int yEnd, int numOfPass, double tariff){
    unsigned long length;
    Point start = Point(xStart, yStart);
    Point end = Point(xEnd, yEnd);

    Node* startNode = grid.getNode(xStart, yStart);
    Node* endNode = grid.getNode(xEnd, yEnd);
    BFS bfs = BFS();

    // Mark all the vertices as not visit
    grid.initDistanceForAll(-1);
    std::list<Node*> path = bfs.funcBFS(startNode, endNode);
    length = path.size();

    return Trip(length, id, 0, numOfPass, tariff, start, end);
}