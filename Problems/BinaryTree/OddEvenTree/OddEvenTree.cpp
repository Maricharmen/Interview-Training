/**
 * Even Odd Tree
 * 
 * A binary tree is named Even-Odd if it meets the following conditions:
 * 
 * - The root of the binary tree is at level index 0, its children are at level 
 * index 1, their children are at level index 2, etc.
 * 
 * - For every even-indexed level, all nodes at the level have odd integer values 
 * in strictly increasing order (from left to right).
 * 
 * - For every odd-indexed level, all nodes at the level have even integer values 
 * in strictly decreasing order (from left to right).
 * 
 * Given the root of a binary tree, return true if the binary tree is Even-Odd, 
 * otherwise return false.
 */

/*
               1   - 0 ->Even
          4        2   - 1 -> Odd  Decreasing
       5   7     9  11 - 2 -> Even Increasi

Input: Root Node
Output: Boolean T/F

BREAKDOWN:
- 
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

class Solution_V1 {    
public:

    TreeNode* root;

    bool isOdd( int value) {
        if(value%2 == 1) return true;
        return false;
    }

    bool isEven( int value) {
        if(value%2 == 0) return true;
        return false;
    }
    
    /**
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */

    bool isEvenOddTree( TreeNode* root ){

        queue<TreeNode*> Q;
        int level = 0;
        
        Q.push(root);

        while( !Q.empty()){

            int size = Q.size();
            int prev = -1;

            for( int i = size; i > 0; i--){
                TreeNode* current = Q.front();
                Q.pop();

                if( isEven(level) ){

                    if( !isOdd(current->data)) return false;
                    else if(prev != -1 && prev >= current->data)return false;
                    
                }else if( isOdd(level) ){

                    if( !isEven(current->data)) return false;
                    else if(prev != -1 && prev <= current->data)return false;
                    
                }

                if( current->left != nullptr) Q.push(current->left);
                if( current->right != nullptr) Q.push(current->right);

                prev = current->data;
            }

            level++;
        }

        return true;

    }

    TreeNode* buildTree( vector<int>& tree, int id){
        if( id >= tree.size()){
            return nullptr;
        }

        TreeNode* newNode = new TreeNode(tree[id]);

        newNode->left = buildTree( tree, 2*id + 1); 
        newNode->right = buildTree(tree, 2*id + 2);

        return newNode;

    }

    void printTree(TreeNode* root){
        if( root == nullptr) return;

        cout<<root->data<<" ";
        printTree(root->left);
        printTree(root->right);

    }

    void printSolution( vector<int>& tree){
        root = buildTree(tree, 0);
        cout<<isEvenOddTree(root)<<"\n";
        //printTree(root);cout<<"\n";
    }
};


void testCases(){
    vector<vector<int>> testCases {
        {1,4,2,5,7,9,11}, // Expected: 1
        {1,2,4,5,7,9,11}, //Expected: 0
        {5,4,2,3,3,7} // Expected: 1
    };

    Solution_V1 sol;

    for( auto test : testCases){
        sol.printSolution(test);
    }
}

int main(){
    testCases();
}
