/*
Site: LeetCode
Topic: Binary Tree 

222. Count Complete Tree Nodes

Approach: Recursion

Required Time: 
Complexity Time: 
Complexity Space: 

Assumpitions: 

*/

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left, *right; 

    Node( int d, Node* l = nullptr, Node* r = nullptr) : data(d), left(l), right(r) {}

};

int countNodes( Node* root ){
    if( root == nullptr ) return 0; 

    return 1 + countNodes(root->left) + countNodes(root->right);
}

Node* insert( Node* root, int data){
    if( root == nullptr ){
        Node* newNode = new Node(data);
        return newNode; 
    }else if( data >  root->data ){
        root->right = insert( root->right, data );
    }else{
        root->left = insert( root->left, data );
    }

    return root; 
}

void dfs_InOrder( Node* root){
    if( root == nullptr) {
        return;
    }
    
    dfs_InOrder( root->left);
    cout<<root->data<<" ";
    dfs_InOrder( root->right);
}

int main(){

    Node* child5 = new Node(6); 
    Node* child4 = new Node(5); 
    Node* child3 = new Node(4); 
    Node* child2 = new Node(3, child5); 
    Node* child1 = new Node(2, child3, child4); 
    Node* root = new Node(1, child1, child2); 

    dfs_InOrder(root); cout<<"\n";
    int totalNodes = countNodes( root );
    cout<<totalNodes<<"\n"; 

    return 0;

}