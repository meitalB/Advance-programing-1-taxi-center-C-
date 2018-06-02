
#ifndef NEWEX1_NODE_H
#define NEWEX1_NODE_H

#include <list>
#include <iosfwd>

using namespace std;

class Node {
private:
    Node* parent;
    int distance;
    list<Node*> neighbors;
public:
    //print the value
    virtual void printValue(ostream &os) const = 0;

    //overloading ==
    virtual bool operator== (const Node&) = 0;

    //get the neighbors of the current node
    std::list<Node*> getNeighbors();

    //get the parent of the current node
    Node* getParent();

    //set the parent of the current node
    void setParent(Node *p);

    //get the distance of the current node
    int getDistance();

    //set the distance of the current node
    void setDistance(int d);

    //add a neighbor to the current node
    void addNeighbor(Node *n);
};

ostream& operator<< (ostream& os, const Node& n);


#endif //NEWEX1_NODE_H
