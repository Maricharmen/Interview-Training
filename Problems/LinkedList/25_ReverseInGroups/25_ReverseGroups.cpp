/**
 * 25. Reverse Linked List in Groups of k
 * 
 * Given the head node of a linked list, reverse the linked list in
 * groups of k
 */

/*

4 8 5 3 6 6 9 1
k=2

8 4 3 5 6 6 1 9

k=3

    |
8 4 3 -  5 6  6 - 1 9

3 4 8


*/


#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int d, Node* n = nullptr) :
    data(d), next(n) {}
};

class Solution_V1{
public:

    Node* reverse(Node* head, int k, int& reversedCount) {
        
        if (head == nullptr || reversedCount == k) return head;

        Node* nodeNext = head->next;
        reversedCount++;

        Node* current = reverse(nodeNext, k, reversedCount);

        // Asegúrate de que nodeNext no sea nullptr antes de acceder a nodeNext->next
        if (nodeNext != nullptr) {
            nodeNext->next = head;
        }

        head->next = nullptr;

        return current;
        }

    Node* reverseGroups(Node* head, int k) {
        Node* current = head;
        int count = 0;

        while (current != nullptr && count < k) {
            current = current->next;
            count++;
        }

        if (count == k) {
            int reversedCount = 1;

            Node* newHead = reverse(head, k, reversedCount);

            head->next = reverseGroups(current, k);

            return newHead;
        }

        return head;
    }

    Node* insert(int data, Node* list){
        if( !list ) return new Node(data);

        Node* newNode = new Node(data);
        Node* last = list;

        while( last->next != nullptr){
            last = last->next;
        }

        last->next = newNode;

        return list;

    }

    Node* buildList( vector<int>& elements){
        Node* list = nullptr;

        for( auto i : elements){
            list = insert(i, list);
        }

        return list;
    }

    void print( Node* list ){
        Node* current = list;
        while(current != nullptr){
            cout<<current->data<<" ";
            current = current ->next;
        }
        cout<<"\n";
    }

    void printSolution(vector<int>& elements, int k){
        Node* list;

        list = buildList(elements);
        print(list);

        Node* reverse = reverseGroups(list, k);
        print(reverse);
    }
};

void testCases(){
    vector< pair<vector<int>, int>> testCases {
        {{4,8,5,3,6,6,9,1}, 3}, // Expected: 5 8 4 6 6 3 9 1
        {{1,2,3,4,5}, 3}, // Expected: 3 2 1 4 5
    };

    Solution_V1 sol;

    for( auto test : testCases){
        sol.printSolution(test.first, test.second);
    }

}

int main(){
    testCases();
}
