/**
 * Invert Binary Tree
 * 
 * Given the root of a binary tree, invert the tree, and 
 * return its root.
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int data;
    TreeNode *left, *right;

    TreeNode( int d, TreeNode* l = nullptr, TreeNode* r = nullptr) :
    data(d), left(l), right(r) {}
};

/**
 * Version 1
 * Approach: Swap Pointers
 */

class Solution_V1{
public:

    TreeNode* root;

    Solution_V1() : root(nullptr) {}

    /**
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */

    TreeNode* invertTree( TreeNode* root){

        if( root == nullptr ) return root;
        
        TreeNode* current = new TreeNode(root->data);

        current->left = invertTree(root->right);
        current->right = invertTree(root->left); 

        root->left = current->right;
        root->right = current->left;

        return current;

    }

    TreeNode* builTree( vector<int>& tree, int id){
        if( id >= tree.size()) return nullptr;

        TreeNode* newNode = new TreeNode(tree[id]);

        newNode->left = builTree(tree, 2*id + 1);
        newNode->right = builTree(tree, 2*id + 2);

        return newNode;
    }

    // In-Order
    void printTree( TreeNode* current){
        if( current == nullptr) return;

        cout<<current->data<<" ";
        printTree(current->left);
        printTree(current->right);
    }

    void printSolution( vector<int>& tree){
        root = builTree(tree, 0);
        printTree(root);

        cout<<"\n";
        root = invertTree(root);
        printTree(root);
    }

};

void testCases(){
    vector<vector<int>> testCases {
        {1,2,3,4,5,6,7},  // Expected: 1 3 7 6 2 5 4
    };

    Solution_V1 sol;

    for( auto test : testCases){
        sol.printSolution(test);
    }

}

int main(){
    testCases();
}