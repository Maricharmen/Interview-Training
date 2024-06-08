/*

Site: GeekForGeeks
Topic: Lowest Common Ancestor in a Binary Search Tree.

Given two values n1 and n2 in a Binary Search Tree, 
find the Lowest Common Ancestor (LCA). You may 
assume that both values exist in the tree. 

Approach: 

Required Time: 
Complexity Time: 
Complexity Space: 

Assumpitions: 

     8
   6    12
 3  7  11 14

 3  7 -> 6
 3 11  -> 8

 3 6 -> 8

*/

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left, *right;

    Node( int d, Node* l = nullptr, Node* r= nullptr) : data(d), left(l), right(r)  {}
};

Node* lowestCommonAncestor(Node* root, int n1, int n2){
    
    if( root == nullptr){
        return nullptr; 
    }

    if( root->data > n1 && root->data > n2 ) return lowestCommonAncestor( root->left, n1, n2);

    if( root->data < n1 && root->data < n2 ) return lowestCommonAncestor( root->right, n1, n2);

    return root;
}

Node* insert( Node* root, int data){
    if( root == nullptr){
        Node* newNode = new Node(data);
        return newNode;
    }else if( data > root->data ) return insert(root->right, data);
    else return insert(root->left, data);

    return root;
}

void dfs_InOrder( Node*root){
    if( root == nullptr) return;

    dfs_InOrder( root->left);
    cout<<root->data<<" ";
    dfs_InOrder( root->right);
}

int main( ){

    //Case 1: 

    Node* child6 = new Node(14);
    Node* child5 = new Node(10);
    Node* child4 = new Node(12, child5, child6);
    Node* child3 = new Node(4);
    Node* child2 = new Node(22);
    Node* child1 = new Node(8, child3, child4);
    Node* root = new Node(20, child1, child2);

    dfs_InOrder(root); cout<<"\n";
    int n1 =10, n2=14;
    Node*  ancestor = lowestCommonAncestor(root, n1, n2);
    cout<<ancestor->data<<"\n";

    return 0; 
}