/*

Site: LeetCode
Topic: LinkedList

21. Merge Two Sorted Lists

---Version 1---

Approach: Simultaneus Iteration Two-Pointers
The mergeTwoLists_V1 function employs the Simultaneous Iteration Two-Pointer technique. 
It handles base cases where either list is empty by returning the other list. 
The function initializes a head pointer to the smaller first node between List1 
and List2, ensuring proper initialization of the merged list. Using nested loops, 
it iteratively compares nodes from List2 with nodes from List1, inserting each 
node from List2 into its correct sorted position within List1. This insertion is 
managed with a prev pointer to track the node before the insertion point. After 
merging all nodes of List2 into List1, the function returns head, which points to 
the beginning of the merged sorted list.

Required Time: 
Complexity Time: O(n)
Complexity Space: O(1)
Assumpitions: 


---Version 2---

Approach: Simultaneus Iteration Two-Pointers
The mergeTwoLists_V2 function employs the Simultaneous Iteration Two-Pointer technique. 
Initially, it handles the base cases where one of the lists might be empty. The function 
sets up the head and current pointers of the merged list by comparing the first nodes of 
both input lists. As it iterates through both lists, it appends the smaller node to the 
merged list and advances the pointer of the list from which the node was taken. When one 
list is exhausted, the remaining nodes of the other list are directly appended to the 
merged list. Ultimately, the function returns the head of the merged list, ensuring that 
all nodes are in a sorted sequence.

Required Time: 
Complexity Time: O(n)
Complexity Space: O(1)
Assumpitions: 


---Version 3---

Approach: Recursion
The mergeTwoListsRecursion function recursively merges two sorted linked lists into a single 
sorted linked list. It begins by checking base cases: if either list is empty, it returns the 
other list. Otherwise, it compares the current nodes of List1 and List2. If the node in List1 
has a smaller or equal value, it recursively merges the rest of List1 with List2, setting the 
next pointer of the current node to the result. Conversely, if the node in List2 is smaller, 
it merges the rest of List2 with List1. This process continues until all nodes from both lists 
are merged, and the function returns the head of the resulting merged list.

Required Time: 

Complexity Time: 
O(n)

Complexity Space: 
If we don’t consider the size of the stack for function calls then O(1) 
otherwise O(n).

Assumpitions: 

*/

#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int d, Node* n = nullptr) : data(d), next(n) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    Node* insertAtFront(Node* head, int data) {
        Node* newNode = new Node(data);
        Node* current = head;

        if (head == nullptr) {
            return newNode;
        }

        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;

        return head;
    }

    void createList(vector<int>& list) {
        
        for (int i = 0; i < list.size(); i++) {
            head = insertAtFront(head, list[i]);
        }
       
    }

    void print(Node* head) {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << "\n";
    }
};

class Solution {
public:
    Node* mergeTwoLists_V1(Node* List1, Node* List2) {
        if (!List1) return List2;
        if (!List2) return List1;

        Node* head;
        if (List1->data <= List2->data) {
            head = List1;
        } else {
            head = List2;
            List2 = List1;
            List1 = head;
        }

        Node* prev = nullptr;

        while (List2 != nullptr) {
            while (List1 != nullptr && List1->data <= List2->data) {
                prev = List1;
                List1 = List1->next;
            }

            Node* nextList2 = List2->next;
            if (prev != nullptr) {
                prev->next = List2;
            }
            List2->next = List1;
            prev = List2;
            List2 = nextList2;
        }

        return head;
    }

    Node* mergeTwoLists_V2(Node* List1, Node* List2) {
        if (!List1) return List2;
        if (!List2) return List1;

        Node* head;
        Node* current;

        if (List1->data <= List2->data) {
            head = List1;
            List1 = List1->next;
        } else {
            head = List2;
            List2 = List2->next;
        }

        current = head;

        while (List1 && List2) {
            if (List1->data <= List2->data) {
                current->next = List1;
                List1 = List1->next;
            } else {
                current->next = List2;
                List2 = List2->next;
            }
            current = current->next;
        }

        if (!List1) {
            current->next = List2;
        }
        if (!List2) {
            current->next = List1;
        }

        return head;
    }

    Node* mergeTwoListsRecursion(Node* List1, Node* List2) {
        if (!List1) return List2;
        if (!List2) return List1;

        if (List1->data <= List2->data) {
            List1->next = mergeTwoListsRecursion(List1->next, List2);
            return List1;
        } else {
            List2->next = mergeTwoListsRecursion(List1, List2->next);
            return List2;
        }
    }

    void printSolution(Node* head){
        LinkedList newlist;
        newlist.print(head);
    }

};

void testCases() {
    vector<pair<vector<int>, vector<int>>> testCases{
        {{1, 2, 4}, {1, 3, 4}}, //1 1 2 3 4 4
        {{}, {}}, //
        {{}, {0}} //0
    };

    for ( auto test : testCases) {
        LinkedList list1, list2;
        list1.createList(test.first);
        list2.createList(test.second);

        Solution sol;
        sol.printSolution( sol.mergeTwoLists_V1(list1.head, list2.head));
    }
    
}

int main() {
    testCases();
    return 0;
}
