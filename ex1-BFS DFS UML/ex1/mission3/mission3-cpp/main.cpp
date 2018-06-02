#include <iostream>
#include "stdlib.h"
#include "Node.h"
#include <math.h>
/**
 * This program create an binary tree, and travels along the tree in a DFS way.
 * This program recives by the program arguments a number,
 * which represent the number of leaves of the tree.
 *
 * @param argc is the numder of arguments.
 * @param argv is array of strings of the arguments.
 * @return 0 if the program run ptopertly.
 */
int main(int argc, char* argv[]) {
    if (argc >= 2) {
        //calculates the high of the tree.
        int maxHigh = (int) (log(atoi(argv[1])) / log(2));
        // creates the first node of the tree- the root.
        Node* root = new Node();
        // adds all the child - create the tree.
        root->spacialAdd(maxHigh, 0);
        // travels along the tree in a DFS way.
        root->dfs();
        // deletes the tree.
        delete root;
        return 0;
    }
    return 1;
}