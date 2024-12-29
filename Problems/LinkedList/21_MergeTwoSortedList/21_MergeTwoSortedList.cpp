/**
 * 21. Merge Two Sorted List 
 * 
 * You are given the heads of two sorted linked lists list1 and list2.
 * 
 * Merge the two lists into one sorted list. The list should be made by splicing 
 * together the nodes of the first two lists.
 * 
 * Return the head of the merged linked list.
 */

/**
 * Input: Heads of two linked lis
 * Output: The head of the merged list 
 * 
 * Assuptions: Sorted is acendent 
 * 
 * BREAKDOWNS:
 * - The first element(head) is the smallest element, at the begining set my head 
 * before to do the merge 
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node( int d, Node* next= nullptr) : data(d), next(next) {}
};

class Solution_V1{
public:
    Node* mergeTwoSortedList( Node* list1, Node* list2){

        if(!list1) return list2;
        if(!list2) return list1;

        Node* head;
        Node* current;

        if( list1->data <= list2->data){
            head = list1;
            list1 = list1->next;
            
        }else{
            head = list2;
            list2 = list2->next;
        }

        current = head;

        while( list1 && list2){

            if( list1->data <= list2->data){
                current->next = list1;
                list1 = list1->next;
            }else{
                current->next = list2;
                list2 = list2->next;
            }

            current = current->next;
        }

        if( !list1 ){
            current->next = list2;
        }else {
            current->next = list1;
        }

        return head;

    }

    Node* insert(int data, Node* head ){
        Node* newNode = new Node(data);

        if( head == nullptr ) return newNode;

        Node* tail = head;

        while( tail->next != nullptr){
            tail = tail->next;
        }

        tail->next = newNode;

        return head;
    }

    Node* buildLinkedList( vector<int>& elements){

        Node* list = nullptr;

        for( int i=0; i < elements.size(); i++){
            list = insert(elements[i], list);
        }

        return list;
    }

    void printSolution( vector<int>& elementsL1, vector<int>& elementsL2 ){

        Node* list1 = buildLinkedList(elementsL1);
        printList(list1);
        Node* list2 = buildLinkedList(elementsL2);
        printList(list2);

        Node * head = mergeTwoSortedList(list1, list2);
        
        while( head != nullptr ){
            cout<<head->data<<" ";
            head= head->next;
        }
        cout<<"\n";
    }

    void printList(Node* list){
        Node* current = list;

        while( current != nullptr){
            cout<<current->data<<" ";
            current= current->next;
        }

        cout<<"\n";
    }

};

class Solution_V2{
public:

    Node* mergeList( Node* list1, Node* list2){
        if( list1 == nullptr) return list2;
        if( list2 == nullptr) return list1;

        if( list1->data < list2->data){
            list1->next = mergeList(list1->next, list2);
            return list1;
        }else{
            list2->next = mergeList(list1, list2->next);
            return list2;
        }

    }

    Node* insert( Node* head, int data){

        if( head == nullptr) return new Node(data);

        Node* newNode = new Node(data);
        Node* current = head;

        while( current->next !=  nullptr){
            current = current->next;
        }

        current->next = newNode;

        return head;
    }

    Node* buildLinkedList( vector<int>& list){
        Node* linkedList = nullptr;

        for( int i=0; i < list.size(); i++){
            linkedList = insert(linkedList, list[i]);
        }

        return linkedList;
    }

    void printSolution(vector<int>& List1, vector<int>& List2){

        Node* list1 = buildLinkedList(List1); printList(list1);
        Node* list2 = buildLinkedList(List2); printList(list2);

        Node* list = mergeList(list1, list2);
        printList(list);

    }

    void printList( Node* list ){
        Node* current = list;

        while( current != nullptr){
            cout<<current->data<<" ";
            current = current->next;
        }

        cout<<"\n";
    }
};

void testCases(){
    vector< pair<vector<int> , vector<int>>> testCases {
        { {1,2,3,4,5}, {3,6,9,10}}, // Expected 1->2->3->3->4->5->6->9->10
        { {1,6,8}, {2,3,4,5,9}} //Expected 1->2->3->4->5->6->8->9
    };

    Solution_V2 sol;

    for( auto test : testCases){
        sol.printSolution(test.first, test.second);
    }
}

int main(){
    testCases();
}

