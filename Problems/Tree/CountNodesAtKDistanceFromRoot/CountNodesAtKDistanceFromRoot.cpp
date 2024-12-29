/**
 * Count Nodes
 * 
 * Count all nodes until k distance from root
 * Given a root of a tree, and an integer k. Count all the nodes until
 * k distance from root.
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode( int v, TreeNode* l = nullptr, TreeNode* r= nullptr) : 
    value(v), left(l), right(r) {}

};

/**
 * Version 1
 * Approach: Tree - BFS
 * Assumpitions: 
 */

class Solution_V1{
private:
    TreeNode* head;

public:

    /**
     * Complexity Time: O(N)
     * Complexity Space: O(h)
     */

    int countNodesKDistance( int k){

        queue<TreeNode*> Q;
        int totalNode = 0;

        Q.push(head);

        int level = 0; 

        while( !Q.empty()){

            int sizeQueue = Q.size();

            for( int i= sizeQueue; i > 0; i--){

                TreeNode* currentNode = Q.front();
                Q.pop();

                if( k >= level ) totalNode++;

                if( currentNode->left != nullptr) Q.push(currentNode->left);
                if( currentNode->right != nullptr) Q.push(currentNode->right);

            }

            level++;
        }


        return totalNode;

    }

     TreeNode* buildTree( vector<int>& tree, int id){

        if( id >= tree.size() || !tree[id]  ) return nullptr;

        TreeNode* newNode = new TreeNode(tree[id]);
        newNode->left = buildTree(tree, 2*id + 1);
        newNode->right = buildTree(tree, 2*id + 2);

        return newNode;
    }

    void printSolution(int k, vector<int> tree){
        head = buildTree(tree, 0);
        cout<<countNodesKDistance(k)<<"\n";
    }

    void printTreeDFS(TreeNode* current){
        if( current== nullptr) return;

        cout<<current->value<<" ";
        printTreeDFS(current->left);
        printTreeDFS(current->right);
    }
};

/**
 * Version 2
 * Approach: DFS
 */

class Solution_V2{
public:
    TreeNode* head;

    /**
     * Complexity Time: O(n)
     * Complexity Space: O(n)
     */

    int countNodes( TreeNode* head, int k){

        if( head == nullptr || k < 0) return 0;
        
        return 1 + countNodes(head->left, k - 1) + countNodes(head->right, k-1);

    }

    TreeNode* buildTree( vector<int>& tree, int id){
        if( id > tree.size() || !tree[id]) return nullptr;

        TreeNode* newNode = new TreeNode(tree[id]);
        newNode->left = buildTree(tree, 2*id + 1);
        newNode->right = buildTree(tree, 2*id + 2);

        return newNode;
    }

    void printSolution( int k, vector<int>& tree){
        head = buildTree(tree, 0);
        cout<<countNodes(head, k)<<" \n";
    }
};

void testCases(){
    
    vector<pair<int, vector<int>>> testCases {
        { 2 ,  { 1,2,3,4,5,6,7}}, //Expected 7
        { 1 ,  { 1,2,3,4,5,6,7}}, //Expected 3
        { 0 ,  { 1,2,3,4,5,6,7}}, // Expected 1
        { 2 ,  {1,2,3,NULL,5,6,NULL}}, // Expected 5
    };

    Solution_V2 sol;

    for( auto test : testCases){
        sol.printSolution(test.first, test.second);
    }

}

int main(){
    testCases();
    return 0;
}