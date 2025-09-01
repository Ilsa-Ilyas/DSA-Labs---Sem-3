#include <iostream>
using namespace std;

// Node class represents each element in the linked list
class Node {
    public:
    int val;       // Value stored in the node
    Node* next;    // Pointer to the next node in the list

    // Constructor to initialize a node with a value and next pointer as NULL
    Node (int val) {
        this->val = val;
        next = NULL;
    }
};

// LINKED LIST CLASS
class Single {
    public:
    Node* head;    // Pointer to the first node in the list
    Node* tail;    // Pointer to the last node in the list

    // Constructor initializes an empty linked list with head and tail as NULL
    Single() {
        head = NULL;
        tail = NULL;
    }

    // Method to insert a new node at the beginning of the list
    void first(int val) {
        Node* newNode = new Node(val);   // Create a new node with the given value

        // If list is empty, set head to the new node
        if (head == NULL) {
            head = newNode;
            return;
        }
        else {
            // Otherwise, link the new node to current head and update head
            newNode->next = head;
            head = newNode;
        }
    }
};



int main() {







    return 0;
}