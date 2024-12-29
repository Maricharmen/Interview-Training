/**
 * 938. Range Sum of BST
 * 
 * Given the root node of a binary search tree and two integers low and high, return the sum 
 * of values of all nodes with a value in the inclusive range [low, high].
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left, * right;

    TreeNode( int d, TreeNode* l= nullptr, TreeNode* r = nullptr) :
    data(d), left(l), right(r) {}
};

/**
 * Version 1
 * Approach: DFS
 */

class Solution_V1 {
public:

    TreeNode* head;

    /**
     * Complexity Time: O(n)
     * Complexity Space: O(n)
     */

    int sumNodes( TreeNode* head, int low, int high){

        if( head == nullptr) return 0;

        int totalSum = 0;

        if( head->data >= low && head->data <= high){
            totalSum += head->data;
        }

        totalSum+= sumNodes(head->left, low, high);
        totalSum+= sumNodes(head->right, low, high);

        return totalSum;
    }

    TreeNode* buildTree( vector<int>& tree, int id){
        if( id >= tree.size() || !tree[id]) return nullptr;

        TreeNode* newNode = new TreeNode(tree[id]);

        newNode->left = buildTree(tree, 2*id + 1);
        newNode->right = buildTree(tree, 2*id + 2);

        return newNode;
    }

    void printSolution( int low, int high, vector<int>& tree){
        head = buildTree(tree, 0);
        cout<<sumNodes( head, low, high)<<"\n";
    }

};

void testCases(){
    vector<pair< pair<int, int>, vector<int>>> testCases {
        { {4,12}, {10, 8,15,5,7,13,17}}, //Expected: 30
    };

    Solution_V1 sol;

    for( auto test : testCases ){
        sol.printSolution(test.first.first, test.first.second, test.second);
    }
}

int main(){
    testCases();
}