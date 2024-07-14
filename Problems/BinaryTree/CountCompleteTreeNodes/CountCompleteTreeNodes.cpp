/**
 * 222. Count Complete Tree Nodes
 * 
 * Given the root of a complete binary tree, return the number of the nodes 
 * in the tree.
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;

    TreeNode( int d, TreeNode* l = nullptr, TreeNode* r= nullptr) :
    data(d), left(l), right(r) {}

};

/**
 * Version 1
 * Approach: DFS
 */

class Solution_V1 {
public:

    TreeNode* head;

    /**
     * Complexity Time: O(n)
     * Complexity Space: O(n)
     */

    int countNodes( TreeNode* head ){
        if( head == nullptr) return 0;

        return 1 + countNodes( head->left) + countNodes( head->right);
    }

    TreeNode* buildTree( vector<int>& tree, int id){

        if( id >= tree.size() || !tree[id]) return nullptr;

        TreeNode* newNode = new TreeNode(tree[id]);
        newNode->left = buildTree( tree, 2*id + 1); 
        newNode->right = buildTree( tree, 2*id + 2);

        return newNode; 

    }

    void printTree(TreeNode* head){
        if( head == nullptr) return;

        cout<<head->data<<" ";

        printTree(head->left);
        printTree(head->right);
    }

    void printSolution(vector<int>& tree){
        head = buildTree( tree, 0 );
        //printTree(head);
        cout<<countNodes(head)<<"\n";
    }
};

void testCases(){
    vector<vector<int>> testCases {
        {1,2,3,4,5}, //Expected: 5
    };

    Solution_V1 sol;

    for( auto test : testCases){
        sol.printSolution(test);
    }
}

int main(){
    testCases();
    return 0;
}