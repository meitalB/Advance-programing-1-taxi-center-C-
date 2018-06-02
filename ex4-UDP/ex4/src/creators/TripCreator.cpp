//
// Created by noam on 16/12/16.
//

#include "TripCreator.h"
//help to create a trip
Trip* createTrip(Matrix *grid, int id, int xStart, int yStart,
                int xEnd, int yEnd, int numOfPass, double tariff, int timeOfStart){
    unsigned long length;
    Point start = Point(xStart, yStart);
    Point end = Point(xEnd, yEnd);

    grid->initDistanceForAll(-1);

    Node* startNode = grid->getNode(xStart, yStart);
    Node* endNode = grid->getNode(xEnd, yEnd);

    // Mark all the vertices as not visit
    std::list<Node *> pathNodes = BFS(startNode, endNode);
    std::vector<Point> pathPoints;
    length = pathNodes.size();
    for (int i = 0; i < length; ++i) {
        Node *n = pathNodes.front();
        Point p = grid->getPoint(n);
        pathPoints.push_back(p);
        pathNodes.pop_front();
    }

    return new Trip(length, id, 0, numOfPass, tariff, start, end, pathPoints, timeOfStart);
}