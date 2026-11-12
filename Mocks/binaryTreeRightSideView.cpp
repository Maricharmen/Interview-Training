/*

Given the root of a binary tree, imagine yourself 
standing on the right side of it, return the values 
of the nodes you can see ordered from top to bottom.

Similar: https://leetcode.com/problems/binary-tree-right-side-view/description/?utm_source=chatgpt.com


            5
      2          4
 1       3 
      7    2

           10 
        /       \
      8          15
    /   \      /    \
   5      9   12    20
  /
 2
 
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v, TreeNode* l, TreeNode* r ) : 
    val(v), left(l), right(r) {}

};

class Solution{
    
public:
    
    vector<int> nodesCanSeeRightSide( TreeNode* root){
        
        if( !root ) return {};

        vector<int> path;
        queue<TreeNode*> q; 
        q.push(root);

        while( !q.empty() ){
            int size = q.size();
            int find = size - 1;
            for( int i=0; i < size; i++){
                TreeNode* currNode = q.front();
                q.pop();
                if( i == find){
                    path.push_back(currNode->val);
                }
                if(currNode->left) q.push(currNode->left);
                if(currNode->right) q.push(currNode->right);
            }
        }

        return path;
        
    }

    void dfs(TreeNode* node, int depth, vector<int>& result ){
        if(node == nullptr) return;

        if(depth == result.size()){
            result.push_back(node->val);
        }

        dfs(node->right, depth + 1, result);
        dfs(node->left, depth + 1, result);
    }

    vector<int> nodesCanSeeRightSide_V2(TreeNode* root){
        vector<int> result = {};
        dfs(root, 0, result);
        return result;

    }

    void printSolution(TreeNode* root){
        for( int i : nodesCanSeeRightSide_V2(root)){
            cout << i << " ";
        }
        cout << "\n";
    }


};

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
    sol.printSolution(&e); // In: 10   Out: [ 10, 15, 20, 2] 

    a = TreeNode(9,nullptr,nullptr);
    b = TreeNode(7,nullptr,nullptr);
    c = TreeNode(3,&b,&a);
    e = TreeNode(1,nullptr,nullptr);
    d = TreeNode(5,&c,&e);
    
    sol.printSolution(&d); // In: 5 Out: [5, 1, 9]

    a = TreeNode(9,nullptr,nullptr);
    b = TreeNode(7,nullptr,nullptr);
    c = TreeNode(3,&b,&a);
    d = TreeNode(5,&c,nullptr);
    
    sol.printSolution(&d); // In: 5 Out: [5, 3, 9]
  
}