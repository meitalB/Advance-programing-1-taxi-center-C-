//
// Created by noam on 16/11/16.
//

#include "Node.h"
#include "iostream"

/**
 * @return the left child of the node.
 */
Node * Node::getLeft() {
    return this->left;
}

/**
 * @return the right child of the node.
 */
Node * Node::getRight() {
    return this->right;
}

/**
 * add a chiid to the left.
 * @param n - the "child" (Node).
 */
void Node::addLeft(Node *n) {
    this->left = n;
}

/**
 * add a chiid to the right.
 * @param n - the "child" (Node).
 */
void Node::addRight(Node *n) {
    this->right = n;
}

/**
 * this function adds the nodes of the tree.
 * adds for each node two children (left and right) by recursion.
 * stops when the current High of the tree at this moment equal
 * to the recomended high of the tree(maxHigh).
 * @param maxHigh is the recomended high.
 * @param currentHigh is the current high of the tree during the recursion.
 */
void Node::spacialAdd(int maxHigh, int currentHigh) {
    if (maxHigh != currentHigh) {

        this->addLeft(new Node());
        this->addRight(new Node());

        this->left->spacialAdd(maxHigh, ++currentHigh);
        this->right->spacialAdd(maxHigh, currentHigh);
    }
}

/**
 *  travels along the tree in a DFS way by recursion.
 */
void Node::dfs() {
    if (this->left) {
        this->left->dfs();
    }

    if (this->right) {
        this->right->dfs();
    }
}
/**
 * destuctor - delets the tree by recursion.
 */
Node::~Node() {
    delete this->left;
    delete this->right;
}

/**
 * constructor.
 * @return  The node
 */
Node::Node() {
    this->left = NULL;
    this->right = NULL;
}


