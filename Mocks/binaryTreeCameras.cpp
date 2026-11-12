/*

Binary Tree Cameras 

You are given the root of a binary tree. We install cameras on the 
tree nodes where each camera at a node can monitor its parent, 
itself, and its immediate children.

Return the minimum number of cameras needed to monitor all nodes of the tree.

Similar: https://leetcode.com/problems/binary-tree-cameras/description/

        10         1
    7      17      2 
  5  6   12  20    3

  output: 2

            10
       7          17
    5    6      12  20
  2  1  3 4
      4 -> 4/2          3   -> n/3


Level : 4
output: 3

        10         1
    7      17      2 
  5  6             3

  output: 2

  leftside -> level 3
  rightside -> level 2

  if level is odd level/3


                               10(0)(0)-> 1 M=4         
            7(0)(1) -> (1) M=3                 17(1)      
       5(1)(0)->(1) m=2 6(0)                4(0)
  3(1)   4(0)
1  2 (0)   

o: alredy monitored
1: camara 

output: 4

                          0-1
                  0-0               n
              0-2       0-1 
           0-1       0-0     n   
        0-0    n-2  n-2  n        
      n-2  n 
      
   2: Already monitoraded
   0: I need be monitoraded   
   1: Camera

*/

struct TreeNode{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
};

class Solution {
public:

    int cameras = 0;
    int countCameras(TreeNode* root) {
        if( root == nullptr ) return 2;

        int left = minCameraCover(root->left);
        int right =  minCameraCover(root->right);

        if( left == 0 || right == 0 ){
          cameras++;
          return 1;
        }

        if( left == 1 || right == 1){
          return 2;
        }

        return 0;

    }

    int minCameraCover( TreeNode* root){
      cameras = 0;
      if(countCameras(root) == 0){
        cameras++;
      }
      return cameras;
    }
};