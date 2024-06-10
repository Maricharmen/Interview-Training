/*
Site: LeetCode
Link: https://leetcode.com/problems/count-complete-tree-nodes/description/
Topic: Binary Tree 

222. Count Complete Tree Nodes

Given the root of a complete binary tree, return the number of the nodes 
in the tree.

Approach: Recursion - DFS Pre-Order

A recursive DFS approach is implemented in pre-order.
The countNodes function calculates the total number of nodes in a binary
tree. The function takes a pointer to the root of the tree as a parameter.
If the tree is empty, the function return 0. Otherwise, it adds 1 to the
result of counting the nodes in the left and right subtrees, recursively.
This process continues until all nodes in the tree have been counted.

Required Time: 

Complexity Time: 
O(n)

Complexity Space: 
If we don’t consider the size of the stack for function calls then O(1) 
otherwise O(h) where h is the height of the tree. 

Assumpitions: 

*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left, *right; 

    TreeNode( int d, TreeNode* l = nullptr, TreeNode* r = nullptr) : 
    data(d), left(l), right(r) {}
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() : root(nullptr) {}

    TreeNode* createTree(vector<int>& tree, int id) {
        if (id >= tree.size() || tree[id] == -1) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(tree[id]);
        root->left = createTree(tree, 2 * id + 1); 
        root->right = createTree(tree, 2 * id + 2); 

        return root;
    }

    void buildTree(vector<int>& tree) {
        root = createTree(tree, 0);
    }

    void DFS_InOrder( TreeNode* root){
        if( root == nullptr) {
            return;
        }
        
        DFS_InOrder( root->left);
        cout<<root->data<<" ";
        DFS_InOrder( root->right);
    }

    void print() {
        cout<<"[ "; DFS_InOrder(root); cout<<"]";
        cout << endl;
    }
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if( root == nullptr) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right); 
    }
};

void testCases(){
    vector<vector<int>> testCases {
        {1,2,3,4,5,6},
        {1,2,3},
        {1}
    };

    for( auto tree : testCases ){
        BinaryTree test;

        test.buildTree(tree);

        test.print();

        Solution sol;
        cout << sol.countNodes(test.root)<< "\n";
    }
}

int main(){
    testCases(); 
    return 0;
}