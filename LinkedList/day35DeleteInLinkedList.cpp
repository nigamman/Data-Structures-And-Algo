#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        cout << "Destructor Called for: " << this->data << endl;
    }
};

void printLL(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Get the length of the linked list
int getLength(Node* head) {
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
// Delete the head element of the linked list
void deleteHead(Node* &head, Node* &tail) {
    if(head == NULL) return; // If the list is empty, nothing to delete

    // Step 1: create a new node temp which is equal to head 
    Node* temp = head;
    // Step 2: then move head to the next element and mark it head 
    head = temp->next;
    // If the list becomes empty after deletion, update tail
    if (head == NULL) {
        tail = NULL;
    }
    // Disconnect the temp element from the list
    temp->next = NULL;
    // Step 3: delete the temp element
    delete temp;
}

// Delete the tail element of the linked list
void deleteTail(Node* &head, Node* &tail) {
    if(head == NULL) return; // If the list is empty, nothing to delete
    if(head == tail) { // If there's only one element in the list
        delete head;
        head = tail = NULL;
        return;
    }
    // Find the second last node
    Node* prev = head;
    while(prev->next != tail) {
        prev = prev->next;
    }
    // Step 1: update the next of the second last node to NULL
    prev->next = NULL;
    // Step 2: delete the tail node
    delete tail;
    // Step 3: update the tail to the second last node
    tail = prev;
}

// Delete a node in the middle of the linked list
void deleteInMid(Node* &head, Node* &tail, int position) {
    if(position <= 1) {
        deleteHead(head, tail);
        return;
    }
    int length = getLength(head);
    if(position > length) {
        cout << "Cannot Delete, invalid position" << endl;
        return;
    }
    if(position == length) {
        deleteTail(head, tail);
        return;
    }
    // Initialize pointers to traverse the list
    Node* prev = NULL;
    Node* curr = head;
    // Traverse the list until the required position is reached
    while(position != 1) {
        position--;
        prev = curr;
        curr = curr->next;
    }
    // Update the previous node's next pointer to skip the current node
    prev->next = curr->next;
    // Disconnect the current node from the list
    curr->next = NULL;
    // Delete the current node to free memory
    delete curr;
}

int main() {
    // Creation of nodes
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    // Linked list created
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    Node* head = first;
    Node* tail = fifth;

    cout << "Printing the entire Linked List: " << endl;
    printLL(head);
    cout << endl;

    // // Delete Head Element
    // deleteHead(head, tail);
    // cout << "After deleting head element: " << endl;
    // printLL(head);
    // cout << endl;

    // Delete in middle of list
    deleteInMid(head, tail, 2);
    cout << "After deleting element at position 2: " << endl;
    printLL(head);
    cout << endl;

    // // Delete from tail
    // deleteTail(head, tail);
    // cout << "After deleting tail element: " << endl;
    // printLL(head);

    return 0;
}
