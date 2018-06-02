
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
    virtual bool operator== (const Node&) const = 0;

    //get the neighbors of the current node
    std::list<Node*> getNeighbors();

    //get the parent of the current node
    virtual Node* getParent();

    //set the parent of the current node
    virtual void setParent(Node *p);

    //get the distance of the current node
    virtual int getDistance();

    //set the distance of the current node
    virtual void setDistance(int d);

    //add a neighbor to the current node
    virtual void addNeighbor(Node *n);

    friend ostream& operator<< (ostream& os, const Node& n);
};



#endif //NEWEX1_NODE_H
