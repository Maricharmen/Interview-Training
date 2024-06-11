/*
Site: LeetCode
Link: https://leetcode.com/problems/range-sum-of-bst/description/
Topic: Binary Tree

938. Range Sum of BST

Approach: BFS
An iterative BFS approach is implemented. 
The rangeSum function takes the root of the tree and two values that 
represent the range of elements to calculate the sum of their values. 
During each iteration, it verifies if the data of the current node falls 
within the specified range; if it does, it adds it to the sum. 
This process continues until all nodes of the tree have been traversed. 

Required Time: 

Complexity Time: 
O(n)

Complexity Space: 
O(n) 

Assumpitions: 

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left, *right;

    TreeNode( int d, TreeNode* l = nullptr, TreeNode* r = nullptr ) : data(d), left(l), right(r) {}
};

class Solution{
public:
    int rangeSum(TreeNode* root, int low, int high) {
        queue<TreeNode*> elements; 
        elements.push(root); 
        int sum = 0;

        while( !elements.empty() ){

            TreeNode* front = elements.front();

            if(front->left != nullptr) elements.push(front->left);
            if(front->right != nullptr) elements.push(front->right);
                
            if( front->data >= low && front->data <= high){
                sum+= front->data;
            }

            elements.pop();

        }

        return sum; 
    }

    void printSolution(TreeNode* root, int low, int high){
        int totalSum = rangeSum( root, low, high );
        cout<<totalSum<<"\n";
    }

};

class BinaryTree{
public:
    TreeNode* root;

    BinaryTree() : root(nullptr) {}

    TreeNode* createTree( vector<int>& tree, int id ){
        if( id >= tree.size() || !tree[id] ) return nullptr;

        TreeNode* root = new TreeNode(tree[id]);
        root->left = createTree(tree, 2*id + 1);
        root->right = createTree(tree, 2*id + 2);

        return root;
    }

    void buildTree(vector<int>& tree ){
        root = createTree(tree, 0);
    }

    void DFS_InOrder(TreeNode* root ){
        if(root == nullptr) return;

        DFS_InOrder(root->left);
        cout<<root->data<<" ";
        DFS_InOrder(root->right);
    }

    void print( TreeNode* root){
        cout<<"["; DFS_InOrder(root); cout<<"] \n";
    }
};

void testCases(){

    vector< pair<vector<int> , pair<int, int>>> testCases {
        {{10,5,15,3,7,NULL,18}, { 7, 15}}, //32
        {{10,5,15,3,7,13,18,1,NULL,6}, { 6, 10}}, //23 
    };

    for( auto test : testCases ){
        BinaryTree tree;
        tree.buildTree(test.first);
        tree.print(tree.root);

        Solution sol;
        sol.printSolution(tree.root, test.second.first, test.second.second);

    }
}

int main(){
    testCases();
    return 0;
}

