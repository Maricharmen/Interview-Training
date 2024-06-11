/*
Site: GeekForGeeks
Link: https://www.geeksforgeeks.org/count-bst-nodes-that-are-in-a-given-range/
Topic: Binary Tree

938. Range Sum of BST
Given the head of a Binary Search Tree (BST) and a 
range (l, h), count the number of nodes that lie in 
the given range (l, h).

Approach: 
An iterative BFS approach is implemented. 
The rangeNodes function takes the root of the tree and two values that 
represent the range of elements to count the total number of nodes. 
During each iteration, it verifies if the data of the current node falls 
within the specified range; if it does, it adds it to the totalNodes. 
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

    TreeNode(int d, TreeNode* l = nullptr, TreeNode* r = nullptr ) :
    data(d), left(l), right(r) {}
};

class Solution{
public:

    int rangeNodes( TreeNode* root, int low, int high){
        queue<TreeNode*> Q;
        Q.push(root);
        int totalNodes = 0;

        while( !Q.empty() ){

            TreeNode* front = Q.front();
            if( front->left != nullptr ) Q.push(front->left);
            if( front->right != nullptr ) Q.push(front->right);

            if( front->data >= low && front->data <= high) totalNodes++;

            Q.pop();
        }

        return totalNodes;
    }

    void printSolution(TreeNode* root, int low, int high ){
        int totalNodes = rangeNodes(root, low, high);
        cout<<totalNodes<<"\n";
    }

};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() : root(nullptr) {}

    TreeNode* createTree( vector<int>& tree, int id){
        if( id >= tree.size() || !tree[id] ) return nullptr;

        TreeNode* root = new TreeNode(tree[id]);
        root->left = createTree(tree, 2*id + 1);
        root->right = createTree(tree, 2*id + 2);

        return root; 
    }

    void buildTree( vector<int>& tree ){
        root = createTree(tree, 0);
    }

    void DFS_InOrder( TreeNode* root){
        if(root== nullptr) return;

        DFS_InOrder(root->left);
        cout<<root->data<<" ";
        DFS_InOrder(root->right);
    }

    void print( TreeNode* root ){
        cout<<"["; DFS_InOrder(root); cout<<"] \n";
    }

};

void testCases(){
    vector<pair< vector<int> , pair<int, int>>> testCases{
        {{10,5,50,1,NULL, 40,100 }, {5,45}}, //3
        {{10,5,50,1,NULL, 40,100 }, {10,100}}, //4
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
