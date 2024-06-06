/*

Site: LeetCode
Topic: LinkedList

21. Merge Two Sorted Lists

Approach: 

Required Time: 
Complexity Time: 
Complexity Space: 

Assumpitions: 

*/

#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* mergeTwoLists( Node* List1, Node* List2 ){

    if (!List1) return List2;
    if (!List2) return List1;

    Node* head;

    if( List1->data <= List2->data){
         head = List1;
    }else{
         head = List2;
         List2 = List1;
         List1 = head; 
    }

    while( List2 != nullptr ){

        Node* nexthead;
        Node* prev ; 

            while( List1 != nullptr && List1->data <= List2->data){
                prev = List1; 
                List1 = List1->next;
            }

            nexthead = List2 -> next;
            List2->next = List1; 
            prev->next = List2; 

            List1 = List2->next;
            List2 = nexthead;
          
    }

    return head;

}

Node* insert( Node* head, int data ){
    Node* newNode = new Node; 
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

void print( Node* head ){
    Node* current = head;

    while( current != nullptr){
        cout<<  current->data <<" ";
        current = current->next;
    }
    cout<<"\n";
}

Node* createList( vector<int>& newlist ){

    Node* list = nullptr;

    for( int i=0; i<newlist.size(); i++ ){
        list = insert(list, newlist[i]); 
    }

    return list; 
}


int main(){

    vector< pair< vector<int> , vector<int> > > testCases {
        { {4,2,1}, {4,3,1}},
        { { }, { }},
        { { }, {0}}
    };

    for( auto test : testCases){
        Node* list1 = createList( test.first ); 
        Node* list2 = createList( test.second ); 

        list1 = mergeTwoLists(list1, list2);

        print(list1); 

    }

    return 0;
}