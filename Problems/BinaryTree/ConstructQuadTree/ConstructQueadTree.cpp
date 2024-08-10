/**
 * Given a n * n matrix grid of 0's and 1's only. We want to represent 
 * grid with a Quad-Tree.
 * 
 * Return the root of the Quad-Tree representing grid.
 * 
 * A Quad-Tree is a tree data structure in which each internal node has 
 * exactly four children. Besides, each node has two attributes:
 * 
 * val: True if the node represents a grid of 1's or False if the node 
 * represents a grid of 0's. Notice that you can assign the val to True 
 * or False when isLeaf is False, and both are accepted in the answer.
 * 
 * isLeaf: True if the node is a leaf node on the tree or False if the 
 *  has four children.
 * 
 * class Node {
 *  public boolean val;
 *  boolean isLeaf; 
 *  public Node topLeft;
 *  public Node topRight;
 *  public Node bottomLeft;
 *  public Node bottomRight
 * }
 * 
 * We can construct a Quad-Tree from a two-dimensional area using the 
 * following steps:
 * 
 * If the current grid has the same value (i.e all 1's or all 0's) set 
 *  True and set val to the value of the grid and set the four children 
 *  to Null and stop.
 * 
 * If the current grid has different values, set isLeaf to False and set 
 *  to any value and divide the current grid into four sub-grids as shown 
 * in the photo.
 * 
 * Recurse for each of the children with the proper sub-grid.
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    bool val;
    bool isLeaf;
    TreeNode* topLeft;
    TreeNode* topRight;
    TreeNode* bottomLeft;
    TreeNode* bottomRight;

    TreeNode( bool v = false, bool iL = false, 
              TreeNode* tL = nullptr, TreeNode* tR = nullptr, TreeNode* bL = nullptr, TreeNode* bR = nullptr ) :
             val(v), isLeaf(iL), topLeft(tL), topRight(tR), bottomLeft(bL), bottomRight(bR) {}

};

class Solution_V1 {
public:

    TreeNode* root; 

    Solution_V1() : root(new TreeNode()) {}

    TreeNode* construct( vector<vector<int>>& grid){
        return constructTree(grid, 0, 0, grid.size());
    }

    TreeNode* constructTree(vector<vector<int>>& grid, int x, int y, int dimension){
        
        if( isUniform(grid, x, y, dimension)){
            TreeNode* newNode = new TreeNode(grid[x][y], true);
            return newNode;
        }

        TreeNode* node = new TreeNode();
        
        node->topLeft = constructTree(grid, x, y, dimension/2);
        node->topRight = constructTree(grid, x, y + dimension/2, dimension/2);
        node->bottomLeft = constructTree(grid, x + dimension/2, y, dimension/2);
        node->bottomRight = constructTree(grid, x + dimension/2, y+dimension/2, dimension/2);

        return node;
    }

    bool isUniform(vector<vector<int>>& grid, int x, int y, int dimension){
        int value = grid[x][y];

        for( int i=x; i < x + dimension; i++){
            for( int j=y; j < y + dimension; j++ ){
                if( grid[i][j] != value) return false;
            }
        }

        return true;
    }

    void printTree( TreeNode* root){
        if( root==nullptr ) return;

        cout<<" ["<<root->isLeaf<<" "<<root->val<<"] ";
        
        printTree(root->topLeft);
        printTree(root->topRight);
        printTree(root->bottomLeft);
        printTree(root->bottomRight);
    }

    void printSolution( vector<vector<int>>& quadTree){
        root = construct(quadTree);
        printTree(root);
        cout<<"\n";
    }
};

void testCases(){
    vector<vector<vector<int>>> testCases {
      { {   {0,1},
            {1,0}   },

        {   {1,1,1,1,0,0,0,0},
            {1,1,1,1,0,0,0,0},
            {1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1},
            {1,1,1,1,0,0,0,0},
            {1,1,1,1,0,0,0,0},
            {1,1,1,1,0,0,0,0},
            {1,1,1,1,0,0,0,0}  } }
    };

    Solution_V1 sol;

    for( auto test : testCases){
        
        sol.printSolution(test);
    }
}

int main(){
    testCases();
}