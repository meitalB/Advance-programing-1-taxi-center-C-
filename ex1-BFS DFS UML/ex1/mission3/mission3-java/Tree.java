

/**
 * This program create an binary tree, and travels along the tree in a DFS way.
 * This program recives by the program arguments a number,
 * which represent the number of leaves of the tree.
 */

public class Tree {
    private Node root;
    
    /**
     * constrctor.
     * @param n is the number of leaves of the tree.
     */
    public Tree(long n){
        int currentHigh = 0;
        int maxHigh = (int) (Math.log(n) / Math.log(2));
        this.root = new Node();
        this.root.spacialAdd(maxHigh, currentHigh);
    }
    /**
     *create the tree and start the DFS.
     * @param args is the number of leaves of the tree.
     */
    public static void main(String[] args) {
	// convert the program arugment to int;
        long numberOfLeaves = Long.valueOf(args[0]);
	// create a new tree in the recomended size.
        Tree t = new Tree(numberOfLeaves);
	//travels along the tree in a DFS way.
        t.dfs();
    }

       /**
	* start the dfs.
	*/
    public void dfs(){
        this.root.dfs();
    }

	/**
	* inner class - Node of a binary tree;
	*/
    private class Node {
        private Node right;
        private Node left;

 	/**
       	 * @return the left child of the node.
     	 */
        public Node getLeft() {
            return left;
        }

	/**
	 * @return the right child of the node.
	 */
        public Node getRight() {
            return right;
        }

	/**
	 * this function adds the nodes of the tree.
	 * adds for each node two children (left and right) by recursion.
	 * stops when the current High of the tree at this moment equal
	 * to the recomended high of the tree(maxHigh).
	 * @param maxHigh is the recomended high.
	 * @param currentHigh is the current high of the tree during the recursion.
	 */
        public void spacialAdd(int maxHigh, int currentHigh){
            if (!(maxHigh == currentHigh)){
                this.addLeft(new Node());
                this.addRight(new Node());

                this.getLeft().spacialAdd(maxHigh, ++currentHigh);
                this.getRight().spacialAdd(maxHigh, currentHigh);
            }
        }

	/**
	 *  travels along the tree in a DFS way by recursion.
	 */
        public void dfs(){
            if (this.getLeft() != null) {
                this.getLeft().dfs();
            }

            if (this.getRight() != null) {
                this.getRight().dfs();
            }
        }

	/**
     	 * add a chiid to the left.
     	 * @param n - the "child" (Node).
     	 */
        public void addLeft(Node n){
            this.left = n;
        }

	/**
     	 * add a chiid to the right.
     	 * @param n - the "child" (Node).
     	 */
        public void addRight(Node n){
            this.right = n;
        }
    }
}
