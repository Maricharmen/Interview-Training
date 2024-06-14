/*
Site: Mock
Link:
Topic: BinaryTree 

Count all nodes until k distance from root
Given a root of a tree, and an integer k. Count all the nodes until
k distance from root. 

Version 1
Approach: Recursion DFS PreOrder
Required Time: 
Complexity Time: O(n)
Complexity Space: O(h)
Assumpitions:

Version 2
Approach: Recursion DFS PreOrder
Required Time: 
Complexity Time: O(n)
Complexity Space: O(h)
Assumpitions:

Version 3
Approach: BFS
Required Time: 
Complexity Time: O(n)
Complexity Space: O(h)
Assumpitions:

Version 4
Approach: BFS
Required Time: 
Complexity Time: O(n)
Complexity Space: O(h)
Assumpitions:

*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode{
    int data;
    TreeNode* left, *right;

    TreeNode(int d, TreeNode* l = nullptr, TreeNode* r= nullptr) :
    data(d), left(l), right(r) {}
};

class Solution{
public:
    int totalNodes = 0;

    void nodesKDistances_V1( TreeNode* root, int k){
        if( root == nullptr) return;

        if( k >= 0 ){
            totalNodes++;
        }

        nodesKDistances_V1(root->left, k-1);
        nodesKDistances_V1(root->right, k-1);
    }

    int nodesKDistances_V2( TreeNode* root, int k){
        if( root == nullptr || k < 0) return 0;

        return 1 + nodesKDistances_V2( root->left, k-1) + nodesKDistances_V2(root->right, k-1);
    }

    int nodesKDistances_V3( TreeNode* root, int k){

        queue<pair<TreeNode*, int>> Q; 
        Q.push(make_pair(root, 0));
        int totalNodes = 0;

        while( !Q.empty()){

            TreeNode* front = Q.front().first;
            int level = Q.front().second;
            Q.pop();

            if( level <= k) totalNodes++;

            if( front->left != nullptr) Q.push(make_pair(front->left, level + 1));
            if( front->right != nullptr) Q.push(make_pair(front->right, level + 1));

        }

        return totalNodes;
    }

    int nodesKDistances_V4( TreeNode* root, int k){

        if( k == 0 ) return 1;

        queue<TreeNode*>Q;
        Q.push(root);

        int level = 0;
        int totalNodes = 0; 

        while(!Q.empty()){

            int size = Q.size();

            for( int i=0; i<size ; i++){
                TreeNode* front = Q.front();
                if( front->left != nullptr ){
                    Q.push(front->left);
                    totalNodes++;
                }

                if( front->right != nullptr ){
                    Q.push(front->right);
                    totalNodes++;
                }
                Q.pop();
            } 

            level++;

            if( level == k){
                return totalNodes + 1;
            }

        }

    }

    void printSolution( TreeNode* root, int k){
        cout<<nodesKDistances_V2(root, k)<<"\n";
    }
};

class BinaryTree{
public:
    TreeNode* root;
    BinaryTree() : root(nullptr) {}

    TreeNode* createTree( vector<int>& tree, int id){
        if( id >= tree.size( ) || !tree[id]) return nullptr;

        TreeNode* root = new TreeNode( tree[id]);
        root->left = createTree(tree, 2*id + 1);
        root->right = createTree(tree, 2*id + 2);

        return root;
    }
}; 


void testCases(){

    vector<pair<vector<int> , int >> testCases {
        {{1,2,3,4,5,6,7}, {0}},  // 1
        {{1,2,3,4,5,6,7}, {1}},  // 3
        {{1,2,3,4,5,6,7}, {2}},  // 7
        {{1,2,3,NULL,5,6,NULL}, {2}}, //5
    };

    for( auto test : testCases ){
        BinaryTree tree;
        tree.root = tree.createTree(test.first, 0);

        Solution sol;
        sol.printSolution(tree.root, test.second); 
    }

}

int main(){
    testCases();
    return 0;
}
