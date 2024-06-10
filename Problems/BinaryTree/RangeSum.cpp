/*
Site: LeetCode
Topic: Binary Tree

938. Range Sum of BST

Approach: 

Required Time: 
Complexity Time: 
Complexity Space: 

Assumpitions: 

*/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left, *right;

    Node( int d, Node* l, Node* r ) : data(d), left(l), right(r) {}
};

int rangeSumBST(Node* root, int low, int high) {
        queue<Node*> elements; 
        elements.push(root); 
        int sum = 0;

        while( !elements.empty() ){

            Node* front = elements.front();

            if(front->left != nullptr) elements.push(front->left);
            if(front->right != nullptr) elements.push(front->right);
            
            if( front->data >= low && front->data <= high){
                sum+= front->data;
            }

            elements.pop();

        }

        return sum; 
}