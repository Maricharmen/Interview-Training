/**
 * Lowest Common Ancestor in a Binary Search Tree.
 * 
 * Given two values n1 and n2 in a Binary Search Tree, 
 * find the Lowest Common Ancestor (LCA). You may 
 * assume that both values exist in the tree. 
 * 
 *         10  <-
 *     5      13 <-
 *    2 7   11   15 
 *        6     14
 * 
 *          11
 *        5    16
 *           15  17
 *         14
 * N1: 11 N2: 14 -> 13
 *                -> 11
 */

/**
 * Input: Two value, root of the binary search tree
 * Output: LCA
 * 
 * BREAKDOWN:
 * - BST node left less than root, right greter that root
 * - Use BFS
 * - CurrentNode -> LCA
 * - Check if the currentNode is biggest or smallest to know what child add to queue.
 *      -If any conditions is valid return LCA
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left, *right;

    TreeNode(int d, TreeNode* l = nullptr, TreeNode* r= nullptr) :
    data(d), left(l), right(r) {}

};

/**
 * Version 1
 * Approach: BFS
 */
class Solution_V1{
public:
    TreeNode* root;

    int lowestCommumAncestor( TreeNode* root, int num1, int num2){
        queue<TreeNode*> Q;
        Q.push(root);

        int lowestAncestor;

        while( !Q.empty()){

            TreeNode* current = Q.front();
            Q.pop();

            TreeNode* left = current->left;
            TreeNode* right = current->right;

            lowestAncestor = current->data;

            if( current->data < num1 && current->data < num2){
                Q.push(right );
            }

            if( current->data > num1 && current->data > num2){
                Q.push(left);
            }

        }

        return lowestAncestor;
    }

    TreeNode* buildTree( vector<int>& tree, int id){
        if( id >= tree.size() || !tree[id]) return nullptr;

        TreeNode* newNode = new TreeNode(tree[id]);
        newNode->left = buildTree(tree, 2*id + 1);
        newNode->right = buildTree(tree, 2*id + 2);

        return newNode;
    }

    void printSolution( vector<int>& tree, int num1, int num2){
        root = buildTree(tree, 0);
        cout<<lowestCommumAncestor(root, num1, num2)<<"\n";
    }


};

/**
 * Version 2
 * Approach: DFS
 */

class Solution_V2 {
public:

    TreeNode* root;

    int lowestCommonAncestor(TreeNode* root, int p, int q) {
        
        int ancestor = root->data;

        if( root->data < p && root->data < q) ancestor = lowestCommonAncestor(root->right, p, q);
        if( root->data > p && root->data > q) ancestor = lowestCommonAncestor( root->left, p, q);

        return ancestor;
    }

    TreeNode* buildTree( vector<int>& tree, int id){
        if( id >= tree.size() || !tree[id]) return nullptr;

        TreeNode* newNode = new TreeNode(tree[id]);
        newNode->left = buildTree(tree, 2*id + 1);
        newNode->right = buildTree(tree, 2*id + 2);

        return newNode;
    }

    void printSolution( vector<int>& tree, int num1, int num2){
        root = buildTree(tree, 0);
        cout<<lowestCommonAncestor(root, num1, num2)<<"\n";
    }
};

void testCases(){
    vector<pair<pair<int, int>, vector<int>>> testCases {
        { {11,14}, {10,5,13,2,7,11,15,NULL,NULL,NULL,6,NULL,NULL,14}}, //Expected: 13
        { {11,13}, {11,5,16,NULL,NULL,15,17,NULL,NULL,NULL,NULL,14}} //Expected: 11
    };

    Solution_V2 sol;

    for( auto test : testCases){
        sol.printSolution(test.second, test.first.first, test.first.second);
    }
}

int main(){
    testCases();
}

