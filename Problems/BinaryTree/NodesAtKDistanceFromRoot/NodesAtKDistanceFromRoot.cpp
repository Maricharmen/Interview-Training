/**
 * Print nodes at k distance from root
 * Given a root of a tree, and an integer k. Return a vector with the nodes which 
 * are at k distance from root. 
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left, *right;

    TreeNode( int d, TreeNode* l = nullptr, TreeNode* r= nullptr) :
    data(d), left(l), right(r) {}
};

/**
 * Version 1
 * Approach: BFS
 *  
 * */ 
class Solution_V1 {
public:

    TreeNode* head;

    /**
     * Complexity Time: O(n)
     * Complexity Space: O(n)
     */

    vector<int> nodesAtKDistance( TreeNode* head, int k){
        queue<TreeNode*> Q;
        Q.push(head);

        vector<int> Nodes;
        int level = 0;

        while( !Q.empty() ){

            for( int i= Q.size(); i>0; i--){
                
                TreeNode* current = Q.front();
                Q.pop();

                if( level == k) Nodes.push_back(current->data);

                if( current->left != nullptr ) Q.push( current->left);
                if(current->right != nullptr) Q.push(current->right);

            }

            level++;

        }

        return Nodes;
    }

    TreeNode* buildTree( vector<int> & tree, int id){
        if( id >= tree.size() || !tree[id] ) return nullptr;

        TreeNode* newNode = new TreeNode(tree[id]);
        newNode->left = buildTree(tree, 2*id + 1);
        newNode->right = buildTree( tree, 2*id + 2);

        return newNode;

    }

    void printSolution( vector<int>& tree, int k){
        head = buildTree(tree,0);
        for( auto node : nodesAtKDistance(head, k)){
            cout<<node<<" ";
        }
        cout<<"\n";
    }


};

void testCases(){
    vector<pair<int, vector<int>>> testCases {
        { 2, {1,2,3,4,5,6,7,8,9,45}}  //Expected: [4,5,6,7]
    }; 

    Solution_V1 sol;

    for( auto test : testCases){
        sol.printSolution(test.second, test.first);
    }
}

int main(){
    testCases();
}