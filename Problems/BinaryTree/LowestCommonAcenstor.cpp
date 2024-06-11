/*
Site: GeekForGeeks
Link: https://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree/
Topic: Binary Tree 

Lowest Common Ancestor in a Binary Search Tree.

Given two values n1 and n2 in a Binary Search Tree, 
find the Lowest Common Ancestor (LCA). You may 
assume that both values exist in the tree. 

Approach: Recursive - BFS
A recursive BFS approach is implemented. 
The lowestCommonAncestor function takes the root of the binary tree 
and two integer values corresponding to data within the tree as 
parameters. If the root is empty, the function returns nullptr. Otherwise,
if the data of the current root is greater than both values, it means 
both values are in the left subtree. Conversely, if the data of the 
current root is smaller than both values, it means both values are in the
right subtree. This process continues until a condition is no longer fulfilled. 

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

    TreeNode( int d, TreeNode* l = nullptr, TreeNode* r= nullptr) : data(d), left(l), right(r)  {}
};

class Solution{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, int n1, int n2){
    
        if( root == nullptr){
            return nullptr; 
        }

        if( root->data > n1 && root->data > n2 ) 
        return lowestCommonAncestor( root->left, n1, n2);

        if( root->data < n1 && root->data < n2 ) 
        return lowestCommonAncestor( root->right, n1, n2);

        return root;
    }

    void printSolution( TreeNode* root, int n1, int n2){
        TreeNode* newAncestor = lowestCommonAncestor(root, n1, n2);
        cout<<newAncestor->data<<"\n";
    }

};

class BinaryTree{
public:
    TreeNode* root;

    BinaryTree() : root(nullptr) {}
    
    TreeNode* createTree( vector<int>& tree, int id){
        if( id >= tree.size() || tree[id] == -1){
            return nullptr;
        }

        TreeNode* root = new TreeNode(tree[id]);
        root->left = createTree(tree, 2*id + 1);
        root->right = createTree(tree, 2*id + 2);

        return root; 
    }

    void buildTree( vector<int>& tree ){
        root = createTree(tree, 0);
    }

    void DFS_InOrder( TreeNode* root ){
        if( root == nullptr) return;

        DFS_InOrder(root->left);
        cout<<root->data<<" ";
        DFS_InOrder(root->right);

    }

    void print( TreeNode* root){
        cout<<"[ "; DFS_InOrder(root); cout<<"] \n";
    }

};

void testCases(){
    vector<pair<vector<int>, pair<int, int>>> testCases {
        {{20,8,22,4,12,-1, -1, -1, -1,10,14}, { 10, 14}}, //12
        {{20,8,22,4,12,-1, -1, -1, -1,10,14}, { 8, 14}}, //8
        {{20,8,22,4,12,-1, -1, -1, -1,10,14}, { 8, 22}}, //20
    };

    for( auto test : testCases ){
        BinaryTree tree;
        tree.buildTree(test.first);
        tree.print(tree.root);

        Solution sol;
        sol.printSolution(tree.root, test.second.first, test.second.second);
    }
}

int main( ){
    testCases();
    return 0; 
}