/*

Given a binary search tree and a pointer to a node within 
the binary search tree, return the next smallest and next largest value.

Suppose we have the following binary search tree:
        10
      /    \
     5     15
   /     /    \
  2     12    20
         n    n


         
            10 < 9 <-
       /        \
      8 < 9 ->        15
    /   \      /    \
   5      9   12    20
  /
2

           10 > 9 <-
       /        \
      8 > 9  ->         15
    /   \      /    \
   5      9   12    20
  /
2

given 9 smallest: 8

2 5 8 .... 9 ... 10 12 15 20 
           |      

Examples:
Given node 15, the next smallest value is 12 and the next largest value is 20.
Given node 10, the next smallest value is 5 and the next largest value is 12.
Given node 5, the next smallest value is 2 and the next largest value is 10.
Given node 2, Smallest : -1  Greater: 12

 currNode -> node -> node -> givenNode

*/

#include <iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v, TreeNode* l, TreeNode* r ) : 
    val(v), left(l), right(r) {}

};

class Solution{
private:
    int smallest, largest;

public:
    /*
    N is the number of nodes
    H is the height of the tree
    Time Complexity: O(H) - Balanced Tree O(logN) Degenerate BST H = N
    Space Complexity: O(1)
    */
    pair<int, int> findSmallestLargestNode( TreeNode* root, TreeNode* node){
        
        TreeNode* findSmallest = root;
        TreeNode* findLargest = root;
        int currSmallest = -1, currLargest = -1;

        if( !root || !node ) return {};

        while( findSmallest ){
            if( findSmallest->val < node->val ){
                currSmallest = findSmallest->val;
                findSmallest = findSmallest->right;
            }else{
                findSmallest = findSmallest->left;
            }

        }

        while( findLargest ){

            if( findLargest->val > node->val ){
                currLargest = findLargest->val;
                findLargest = findLargest->left;
            }else{
                findLargest = findLargest->right;
            }

        }

        return {currSmallest, currLargest};
    }

    void printSolution(TreeNode* root, TreeNode* node){
        pair<int, int> output = findSmallestLargestNode(root, node);
        cout << output.first << " " << output.second << "\n";
    }


};

/*
           10 > 9 <-
       /        \
      8 > 9  ->         15
    /   \      /    \
   5      9   12    20
  /
2

*/

int main(){

    TreeNode a = TreeNode(2, nullptr, nullptr);
    TreeNode b = TreeNode(5, &a, nullptr);
    TreeNode c = TreeNode(9, nullptr, nullptr);
    TreeNode d = TreeNode(8, &b, &c);
    TreeNode g = TreeNode(12, nullptr, nullptr);
    TreeNode h = TreeNode(20, nullptr, nullptr);
    TreeNode f = TreeNode(15, &g, &h);
    TreeNode e = TreeNode(10, &d, &f);
    Solution sol;
    sol.printSolution(&e, &c); // In: 9  Out: {8,9}
    sol.printSolution(&e, &f); // In: 15 Out: {12,20}

}