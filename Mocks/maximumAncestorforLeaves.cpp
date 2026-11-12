/*

Given a tree where each node holds an integer value, 
write a function that finds and returns a mapping from 
each leaf node to that node's maximum ancestor.

Test 1: 
         9
  3   14   8   22
1    6           n 
n      2

output: {1: 9, 2: 14 8:8 22: 9}


Test 2
         9

output: {}

BREAKDOWN
- I am in a root
- Check if I have child
- If not, I am leaft, make the mapping of leaf value with a current max
- If it is, update the current max with the leaf value

Time Complexity: O(N) n: number of nodes
Space Complexy: O(L + S ) L: Number leaf S: max level of the tree


*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct TreeNode{
    int val;
    vector<TreeNode*> children;

    TreeNode(int v) : val(v) {}
};

class Solution{
private:
    map<int, int> maximumAncestor;

public:

    void mappingMaximumAnscestorforLeaves(TreeNode* root, int currentMax){

        vector<TreeNode*> children = root->children;

        if(children.empty()){
            maximumAncestor[root->val] = currentMax;
            return;
        }

        int nextMax = max(currentMax, root->val);
        for( TreeNode* child : children){
            mappingMaximumAnscestorforLeaves(child, nextMax);
        }
    }

    map<int, int> maximumAnscestorforLeaves(TreeNode* root){
        maximumAncestor.clear();
        int maximum = root->val;

        if( !root || root->children.empty()) return {};

        mappingMaximumAnscestorforLeaves(root, maximum);

        return maximumAncestor;

    }

    void printSolution(TreeNode* root){
        for( auto leaf : maximumAnscestorforLeaves(root)){
            cout << leaf.first << " " << leaf.second<< "\n";
        }
    }
};


// Helper function to free allocated tree memory
void freeTree(TreeNode* root) {
    if (!root) return;
    for (TreeNode* child : root->children) {
        freeTree(child);
    }
    delete root;
}

int main() {
    Solution solver;

    cout << "=== Test Case 1: Standard Tree ===" << endl;
    TreeNode* root1 = new TreeNode(9);
    TreeNode* n3 = new TreeNode(3);
    TreeNode* n14 = new TreeNode(14);
    TreeNode* n8 = new TreeNode(8);
    TreeNode* n22 = new TreeNode(22);
    TreeNode* n1 = new TreeNode(1);
    TreeNode* n6 = new TreeNode(6);
    TreeNode* n2 = new TreeNode(2);

    root1->children = {n3, n14, n8, n22};
    n3->children = {n1};
    n14->children = {n6};
    n6->children = {n2};

    // Expected:
    // Leaf 1  -> 9
    // Leaf 2  -> 14
    // Leaf 8  -> 9
    // Leaf 22 -> 9
    solver.printSolution(root1);
    cout << endl;

    cout << "=== Test Case 2: Single Node Tree ===" << endl;
    TreeNode* root2 = new TreeNode(10);
    // Expected: (No leaves with proper ancestors)
    solver.printSolution(root2);
    cout << endl;


    cout << "=== Test Case 3: All Negative Values ===" << endl;
    TreeNode* root3 = new TreeNode(-50);
    TreeNode* neg_left = new TreeNode(-20);
    TreeNode* neg_leaf1 = new TreeNode(-5);
    TreeNode* neg_leaf2 = new TreeNode(-100);

    root3->children = {neg_left, neg_leaf2};
    neg_left->children = {neg_leaf1};

    // Path to leaf -5: -50 -> -20 -> -5. Max ancestor is max(-50, -20) = -20
    // Path to leaf -100: -50 -> -100. Max ancestor is -50
    // Expected:
    // Leaf -100 -> -50
    // Leaf -5   -> -20
    solver.printSolution(root3);
    cout << endl;


    cout << "=== Test Case 4: Linear Skewed Tree ===" << endl;
    TreeNode* root4 = new TreeNode(5);
    TreeNode* n10 = new TreeNode(10);
    TreeNode* n2_skew = new TreeNode(2);
    TreeNode* n15_leaf = new TreeNode(15);

    root4->children = {n10};
    n10->children = {n2_skew};
    n2_skew->children = {n15_leaf};

    // Path to leaf 15: 5 -> 10 -> 2 -> 15. Max ancestor is max(5, 10, 2) = 10
    // Expected:
    // Leaf 15 -> 10
    solver.printSolution(root4);
    cout << endl;

    // Cleanup
    freeTree(root1);
    freeTree(root2);
    freeTree(root3);
    freeTree(root4);

    return 0;
}

