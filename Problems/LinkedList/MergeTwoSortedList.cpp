/*

Site: LeetCode
Topic: LinkedList

21. Merge Two Sorted Lists

Approach: 

Required Time: 
Complexity Time: O(n)
Complexity Space: O(1)

Assumpitions: 

*/

#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* mergeTwoLists_V1( Node* List1, Node* List2 ){

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

Node* mergeTwoLists_V2( Node* List1, Node* List2 ){
    
    if(!List1) return List2;
    if(!List2) return List1;

    Node* head;
    Node* current;

    if( List1->data <= List2->data ){
        head = List1;
        List1 = List1->next;
    }else{
        head = List2;
        List2 = List2->next;
    }

    current = head;

    while( List1 && List2 ){
        
        if( List1->data <= List2->data){
            current->next = List1;
            List1 = List1->next; 
        }else{
            current->next = List2;
            List2 = List2->next; 
        }

        current = current->next;
    }

    if(!List1){
        current->next = List2;
    }
    if(!List2){
        current->next = List1;
    }

    return head;
}

Node* mergeTwoListsRecursion( Node* List1, Node* List2 ){

    if (!List1) return List2;

    if (!List2) return List1;

    if( List1->data <= List2->data){
        List1->next = mergeTwoListsRecursion( List1->next, List2);
        return List1;
    }else{
        List2->next = mergeTwoListsRecursion( List1, List2->next);
        return List2;
    }

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

    cout<<"V1"<<"\n";

    for( auto test : testCases){
        Node* list1 = createList( test.first ); 
        Node* list2 = createList( test.second ); 

        list1 = mergeTwoLists_V1(list1, list2);
        print(list1);

    }

    cout<<"V2"<<"\n";

    for( auto test : testCases){
        Node* list1 = createList( test.first ); 
        Node* list2 = createList( test.second ); 

        list1 = mergeTwoLists_V2(list1, list2);
        print(list1);

    }

    cout<<"Recursion"<<"\n";

    for( auto test : testCases){
        Node* list1 = createList( test.first ); 
        Node* list2 = createList( test.second ); 

        list1 = mergeTwoListsRecursion(list1, list2);
        print(list1);

    }

    return 0;
}