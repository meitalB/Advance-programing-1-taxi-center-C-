
#include "Node.h"

//get the parent of the current node
Node *Node::getParent() {
    return this->parent;
}

//set the parent of the current node
void Node::setParent(Node *p) {
    this->parent = p;
}

//get the distance of the current node
int Node::getDistance() {
    return this->distance;
}

//set the distance of the current node
void Node::setDistance(int d) {
    this->distance = d;
}

//add a neighbor to the current node
void Node::addNeighbor(Node *n) {
    this->neighbors.push_back(n);
}

//get the neighbors of the current node
std::list<Node *> Node::getNeighbors() {
    return this->neighbors;
}

//print the value
ostream &operator<<(ostream &os, const Node &n) {
    n.printValue(os);
    return os;
}
