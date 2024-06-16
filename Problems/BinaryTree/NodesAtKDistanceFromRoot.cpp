/*
Site: GeekForGeeks
Link: https://www.geeksforgeeks.org/print-nodes-at-k-distance-from-root/
Topic: BinaryTree

Print nodes at k distance from root
Given a root of a tree, and an integer k. Print all the nodes which 
are at k distance from root. 

            1       0
          /   \
        2      3    1
      /  \    /
    4     5  8      2

Version 1

Approach: Recursion DFS - PostOrder
Required Time: 
Complexity Time: O(n)
Complexity Space: O(h)
Assumpitions: 

Version 2
Approach: Recursion DFS - PostOrder
Required Time: 
Complexity Time: O(n)
Complexity Space: O(h)
Assumpitions: 

Version 3
Approach: BFS
Required Time: 
Complexity Time: O(n)
Complexity Space: O(n)
Assumpitions: 

*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left, *right;

    TreeNode(int d, TreeNode* l=nullptr, TreeNode* r = nullptr ) :
    data(d), left(l), right(r) {}
};

class Solution{
public:
    void nodesAtDistance_V1(TreeNode* root, int k, int height){
        if( root == nullptr) return;

        if( k == height){
            cout<<root->data<<" ";
            return;
        }

        nodesAtDistance_V1(root->left, k, height + 1 );
        nodesAtDistance_V1(root->right, k, height + 1 );

    }

    void nodesAtDistance_V2(TreeNode* root, int k){
        if( root == nullptr) return;

        if( k == 0){
            cout<<root->data<<" ";
            return;
        }

        nodesAtDistance_V2(root->left, k-1 );
        nodesAtDistance_V2(root->right, k-1);
    }

    void nodesAtDistance_V3(TreeNode* root, int k){

        queue<TreeNode*>Q;
        Q.push(root);
        int level = 0;

        while(!Q.empty()){

            int size = Q.size();

            for( int i=0; i<size; i++){
                TreeNode* front = Q.front();
                if( front->left ) Q.push(front->left);
                if( front->right ) Q.push(front->right);
                Q.pop();
            }

            level++;

            if( level == k){
                size = Q.size();
                for( int i=0; i<size; i++){
                    cout<<Q.front()->data<<" ";
                    Q.pop();
                }
            }

        }

    }

    
};

class BinaryTree{
public:

    TreeNode* root;

    BinaryTree() : root(nullptr) {}

    TreeNode* createTree( vector<int>& tree, int id){
        if( id >= tree.size() || !tree[id])return nullptr;

        TreeNode* root = new TreeNode(tree[id]);
        root->left = createTree(tree, 2*id + 1);
        root->right = createTree(tree, 2*id + 2);

        return root;
    }

};


void testCases(){
    vector<pair<vector<int>, int>> testCases{
        {{1,2,3,4,5,8}, {2}}, //4 5 8
    };

    for( auto test : testCases){
        BinaryTree tree; 
        tree.root = tree.createTree(test.first, 0);

        Solution sol;

        sol.nodesAtDistance_V3(tree.root,test.second);
    }
}

int main(){
    testCases();
    return 0;
}