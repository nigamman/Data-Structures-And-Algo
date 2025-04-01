#include <iostream>
using namespace std;

// Node class definition
class Node {
public:
    int data;    // Data stored in the node
    Node* next;  // Pointer to the next node

    // Constructor to initialize node with data
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

int main() {
    // Creating individual nodes
    Node* first = new Node(10);   // First node with data 10
    Node* second = new Node(20);  // Second node with data 20    Node* third = new Node(30);   // Third node with data 30

    // Linking nodes together
    first->next = second;  // First node points to second
    second->next = third;  // Second node points to third

    // 'head' is the starting point of the linked list
    Node* head = first;

    // Traversing and printing the linked list
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}

