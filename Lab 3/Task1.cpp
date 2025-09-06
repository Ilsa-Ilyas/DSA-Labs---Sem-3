#include <iostream>
using namespace std;

class Node {
public:
    int data;      // Stores the value of the node
    Node* next;    // Pointer to the next node in the list

    // Constructor
    Node(int val) {
        data = val;
        next = NULL;   // next is set to NULL
    }

    // Setter for data
    void setdata(int val) { data = val; }

    // Getter for data
    int getdata() { return data; }

    // Getter for the next pointer
    Node* getnext() { return next; }

    // Setter for the next pointer
    void setnext(Node* nextNode) { next = nextNode; }
};

class LinkedList {
    Node* head;  // Pointer to the head of the list
    Node* tail;  // Pointer to the tail of the list

public:
    // Constructor
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    // Destructor (frees all nodes)
    ~LinkedList() {
        while (head != NULL) {   // FIX: check head, not head->next
            Node* temp = head;  // Temporary pointer to the current head
            head = head->next;  // Move head to the next node
            delete temp;        // Delete the old head
        }
        head = NULL;  // Set head to NULL
        tail = NULL;  // Set tail to NULL
    }

    // Insert at the beginning
    void first(int val) {
        Node* newNode = new Node(val); // Create a new node with the given value
        if (head == NULL) {              // If the list is empty
            head = newNode;              // Set head to the new node
            tail = newNode;              // Set tail to the new node
        } else {
            newNode->setnext(head);      // Link the new node to the current head
            head = newNode;              // Update head to the new node
        }
    }

    // Insert at end (default) or at given position
    void insert(int value = 0, int position = -1) {
        // Case 1: Insert at the end
        if (position == -1) {
            if (head == NULL) {
                first(value);   // empty list → insert at start
            } else {
                Node* node = new Node(value); 
                tail->setnext(node); // link old tail to new node
                tail = node;         // update tail
            }
        }
        // Case 2: Insert at a given position
        else {
            if (position == 0) { // insert at start
                first(value);
                return;
            }
            Node* node = new Node(value);
            Node* current = head;  // start at head

            // Traverse until (position - 1) or end of list
            for (int i = 0; i < position - 1 && current->getnext() != NULL; i++) {
                current = current->getnext(); // move forward
            }

            node->setnext(current->getnext()); // link new node to next
            current->setnext(node);            // link current to new node

            if (node->getnext() == NULL) { // if inserted at end
                tail = node;
            }
        }
    }

    // Sort function: groups even numbers first, then odd numbers
    void sort() {
        if (!head || head->getnext() == NULL) {
            return; // empty list or single node
        }

        Node* evenHead = NULL; // head of even sublist
        Node* evenTail = NULL; // tail of even sublist
        Node* oddHead = NULL;  // head of odd sublist
        Node* oddTail = NULL;  // tail of odd sublist

        Node* current = head;

        // Separate evens and odds into two lists
        while (current != NULL) {
            if (current->getdata() % 2 == 0) { // even
                if (!evenHead) {
                    evenHead = current;
                    evenTail = current;
                } else {
                    evenTail->setnext(current);
                    evenTail = current;
                }
            } else { // odd
                if (!oddHead) {
                    oddHead = current;
                    oddTail = current;
                } else {
                    oddTail->setnext(current);
                    oddTail = current;
                }
            }
            current = current->getnext();
        }

        // Merge even and odd lists
        if (evenHead) {
            head = evenHead;
            evenTail->setnext(oddHead);
            tail = (oddTail) ? oddTail : evenTail;
        } else {
            head = oddHead;
            tail = oddTail;
        }

        if (tail) tail->setnext(NULL); // terminate list
    }

    // Display the list
    void display() {
        Node* current = head;  // start at head
        while (current != NULL) {
            cout << current->getdata() << " "; // print data
            current = current->getnext();       // move to next node
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int n, val;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insert(val);  // insert at end
    }

    cout << "\nOriginal List: ";
    list.display();  // before sorting

    list.sort();     // rearrange even before odd

    cout << "Modified List: ";
    list.display();  // after sorting

    return 0;
}

