/**
 * Find the Maximum Depth or Height of given Binary Tree
 * 
 * Given a binary tree, the task is to find the height of the tree. 
 * The height of the tree is the number of vertices in the tree from 
 * the root to the deepest node. 
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int data;
    TreeNode*left, *right;

    TreeNode( int d, TreeNode* l = nullptr, TreeNode* r = nullptr) :
    data(d), left(l), right(r) {}

};

/**
 * Version 1
 * Approach: DFS
 */
class Solution_V1{
public:
    TreeNode* head;

    /**
     * Complexity Time: O(n)
     * Complexity Space: O(n)
     */

    int maximumDepth( TreeNode* head ){
        if( head == nullptr) return  0;

        return max( maximumDepth(head->left) , maximumDepth(head->right) ) + 1;

    }

    TreeNode* buildTree( vector<int>& tree, int id){
        if( id >= tree.size() || !tree[id] ) return nullptr;

        TreeNode* newNode = new TreeNode(tree[id]);
        newNode->left = buildTree( tree, 2*id + 1);
        newNode->right = buildTree( tree, 2*id + 2);

        return newNode;
    }

    void printSolution( vector<int>& tree ){
        head = buildTree(tree, 0);
        cout<<maximumDepth(head)<<"\n";
    }
};

void testCases(){
    vector<vector<int>> testCases {
        {1,2,3,4,5,6}, //Expected : 3
        {1,4,5,3,6,NULL,3,NULL,NULL,1,2,3,NULL} //Expected: 4
    };

    Solution_V1 sol;

    for( auto test : testCases){
        sol.printSolution(test);
    }
}

int main(){
    testCases();
}

