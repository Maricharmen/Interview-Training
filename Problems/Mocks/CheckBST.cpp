/*
La primera fue validar un bst

    7
  4   9
2  5    10   

Input: [7, 4,9, 2,5, null, 10]
Process: 

Output: True
 */

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int d, TreeNode* l = nullptr, TreeNode* r = nullptr) : 
    data(d), left(l), right(r) {}
};

class Solution_V1{  

public:

/*
    7
  4   9
2  5    10 


*/

    bool isValid( TreeNode* node, int min, int max){

        if( node == nullptr) return true;

        if( node->data < min || node->data > max) return false;

        return isValid( node->left, min, node->data-1) && 
                isValid( node->right, node->data + 1, max );
        
    }

    TreeNode* buildTree( vector<int>& tree, int id ){
        if( id >= tree.size() || tree[id] == -1 ){
            return nullptr;
        }

        TreeNode* newNode = new TreeNode( tree[id] );
        newNode->left = buildTree( tree, id*2 + 1);
        newNode->right = buildTree( tree, id*2 + 2);

        return newNode;
    }

    void checkBST( vector<int>& tree ){
        TreeNode* root = buildTree( tree, 0);
        cout<< isValid( root, INT_MIN, INT_MAX)<<"\n";
        printTree(root);
    }

    void printTree( TreeNode* current ){
        if( current == nullptr) return;
        
        printTree(current->left);
        cout<<current->data<<" ";
        printTree(current->right);
    }
};

int main(){

    vector<vector<int>> testCases {
        {7, 4, 9, 2, 5, -1 , 10}, // True
    };

    Solution_V1 sol;

    for( auto test : testCases ){
        sol.checkBST(test);
    }

    return 0;
}



