/**
 * 
 * 938. Range Sum of BST
 * 
 * Given the head of a Binary Search Tree (BST) and a 
 * range (l, h), count the number of nodes that lie in 
 * the given range (l, h).
 */

#include <iostream>
#include <vector>
using namespace std;


struct TreeNode{
    int data;
    TreeNode *left, *right;

    TreeNode( int d, TreeNode* l=nullptr, TreeNode* r= nullptr) :
    data(d), left(l), right(r) {}
};

/**
 * Version 1
 * Approach: DFS
 */
class Solution_V1{
public:

    TreeNode* head;

    /**
     * Complexity Time: O(n)
     * Complexity Space: O(n)
     */

    int countNumNodes( TreeNode* head, int low, int high){

        if( head == nullptr ) return 0;
        
        int numNodes = 0;

        if(head->data <= high && head->data >= low){
             numNodes++;
        }
        
        numNodes += countNumNodes( head->left, low, high);
        numNodes += countNumNodes(head->right, low, high);
        
        return numNodes;
    }

    TreeNode* buildTree(vector<int>& tree, int id){
        if( id >= tree.size() || !tree[id]) return nullptr;

        TreeNode* newNode = new TreeNode(tree[id]);
        newNode->left = buildTree(tree, 2*id + 1);
        newNode->right = buildTree( tree, 2*id + 2);

        return newNode;
    }

    void printSolution(int low, int high, vector<int>& tree){
        head = buildTree(tree, 0);
        cout<<countNumNodes( head, low, high)<<"\n";
    }

    void printTree(TreeNode* head){
        if( head == nullptr) return;

        cout<<head->data<<" ";

        printTree(head->left);
        printTree(head->right);

    }
};

void testCases(){
    vector<pair<pair<int, int>, vector<int>>> testCases{
        { {4, 9}, {6,4,8,2,3,7,9,1, NULL}}, //Expected : 5
        { {5,45}, {10,5,50,1,40,100 } }, // Expected: 3
        { {10,100}, {10,5,50,1,NULL, 40,100 }}, // Expected: 4
    };

    for( auto test : testCases){
        Solution_V1 sol;
        sol.printSolution(test.first.first, test.first.second, test.second);
    }
}

int main(){
    testCases();
    return 0;
}