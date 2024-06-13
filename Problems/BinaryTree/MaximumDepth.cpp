/*
Site: GeekForGeeks
Link:https://www.geeksforgeeks.org/find-the-maximum-depth-or-height-of-a-tree/
Topic: Binary Search

Find the Maximum Depth or Height of given Binary Tree
Given a binary tree, the task is to find the height of the tree. 
The height of the tree is the number of vertices in the tree from 
the root to the deepest node. 


Version 1

Approach: Recursive - DFS PostOrder
Required Time: 
Complexity Time: O(n)
Complexity Space: O(n)


Version 2

Approach: BFS
Required Time: 
Complexity Time: O(n)
Complexity Space: O(n)

Version 3

Approach: BFS
Required Time: 
Complexity Time: O(n)
Complexity Space: O(n)

Version 4

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

    TreeNode(int d, TreeNode* l=nullptr, TreeNode* r= nullptr) :
    data(d), left(l), right(r) {}
};

class Solution{
public:
    int maximumHeight_V1(TreeNode* root){
        if( root == nullptr) return 0;

        return max(maximumHeight_V1(root->left), maximumHeight_V1(root->right)) + 1;
    }

    int maximumHeight_V2(TreeNode* root){
        if( root == nullptr) return 0;

        queue<TreeNode*> Q;
        Q.push(root); Q.push(nullptr);
        int maximumHeight = 0;
        
        while(!Q.empty()){       
             
            TreeNode* front = Q.front();
            Q.pop();

            if( front == nullptr) maximumHeight++;

            if(front != nullptr){
                if( front->left != nullptr ) Q.push(front->left);
                if( front->right != nullptr) Q.push(front->right);
            }else if (!Q.empty()){
                Q.push(nullptr);
            }

        }

        return maximumHeight;
    }

    int maximumHeight_V3(TreeNode* root){
        if( root == nullptr) return 0;
        queue<TreeNode*>Q;
        Q.push(root); Q.push(nullptr);
        int maximumHeight = 0;

        while( !Q.empty()){
    
            while( Q.front() != nullptr){
                TreeNode* front = Q.front();
                if( front->left != nullptr) Q.push(front->left);
                if( front->right != nullptr ) Q.push(front->right);
                Q.pop();
            }

            Q.pop();
            maximumHeight++;
            
            if( !Q.empty()){
                Q.push(nullptr);
            }
        }

        return maximumHeight;
    }

    int maximumHeight_V4(TreeNode* root){
        if( root == nullptr) return 0;

        queue<TreeNode*>  Q;
        Q.push(root);
        int maximumHeight = 0; 
        
        while(!Q.empty()){
            int sizeQueue = Q.size();

            for(int i=0; i<sizeQueue; i++){
                TreeNode* front = Q.front();
                if(front->left != nullptr ) Q.push(front->left);
                if(front->right != nullptr ) Q.push(front->right);
                Q.pop();
            }
            maximumHeight++;
        }

        return maximumHeight;
    }

    void printSolution(TreeNode* root){
        int maximumHeight = maximumHeight_V4(root);
        cout<<maximumHeight<<"\n";
    }
};

class BinaryTree{
public:
    TreeNode* root;

    BinaryTree() : root(nullptr) {}

    TreeNode* createNode( vector<int>& tree, int id){
        if( id >= tree.size() || !tree[id]) return nullptr;

        TreeNode* root = new TreeNode(tree[id]);
        root->left = createNode( tree, 2*id + 1);
        root->right = createNode(tree, 2*id + 2);

        return root;
    }

};

void testCases(){
    vector<vector<int>> testCases{
        {1,2,3,4,5}, //3
        {}, // 0
        {1}, // 1
        {1,2,3} // 2
    };

    for( auto test : testCases ){
        BinaryTree tree;
        tree.root = tree.createNode(test, 0);

        Solution sol;
        sol.printSolution(tree.root); 

    }

}

int main(){
    testCases();
    return 0;
}

