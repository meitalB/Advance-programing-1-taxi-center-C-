//
// Created by noam on 16/11/16.
//

#ifndef TREEC_NODE_H
#define TREEC_NODE_H

/**
 * NODE- is a node of binary tree.
 */
class Node {
private:
    Node* left;
    Node* right;
public:
    /**
     * constructor.
     * @return  The node
     */
    Node();

    /**
     * destuctor - delets the tree by recursion.
     */
    ~Node();

    /**
     * @return the left child of the node.
     */
    Node * getLeft();

    /**
     * @return the right child of the node.
     */
    Node * getRight();

    /**
     * add a chiid to the left.
     * @param n - the "child" (Node).
     */
    void addLeft(Node* n);

    /**
     * add a chiid to the right.
     * @param n - the "child" (Node).
     */
    void addRight(Node* n);

    /**
     * this function adds the nodes of the tree.
     * adds for each node two children (left and right) by recursion.
     * stops when the current High of the tree at this moment equal
     * to the recomended high of the tree(maxHigh).
     * @param maxHigh is the recomended high.
     * @param currentHigh is the current high of the tree during the recursion.
     */
    void spacialAdd(int maxHigh, int currentHigh);

    /**
     *  travels along the tree in a DFS way by recursion.
     */
    void dfs();

};


#endif //TREEC_NODE_H
