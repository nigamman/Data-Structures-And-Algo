#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node() {
        this->data = 0;
        this->next = NULL;
        //cout << "I am inside default constructor." << endl;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
        //cout << "I am inside paramtherized constructor." << endl;
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

// I want to insert a node right at the head of Linked List
void insertionAtHead(Node* &head, Node* &tail, int data) {
    // if linked list is NULL
    if (head == NULL) {
        // step 1: create a new node
        Node* newNode = new Node(data);
        // step 2: update node
        head = newNode;
        tail = newNode;
    } 
    else {  // non-empty case
        // step 1: Create a new node;
        Node* newNode = new Node(data);
        // step 2: Make next of new node as head;
        newNode->next = head;
        // step 3: Move the head to point to the new node;
        head = newNode;
    }    
}

// I want to insert a node right at the tail of Linked List
void insertionAtTail(Node* &head, Node* &tail, int data) {
    // Empty Linked List
    if (head == NULL) {
        // Step 1: Create a new Node 
        Node* newNode = new Node(data);
        // Make head and tail point to the new node
        head = newNode;
        tail = newNode;
    } else {
        // Step 1: create a new node
        Node* newNode = new Node(data);
        // Step 2: attach newNode to tail's next
        tail->next = newNode;
        // Step 3: update the tail to the new node
        tail = newNode;
    }
}

int getLength(Node* head) {
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtPosition(Node* &head, Node* &tail, int data, int position) {
    
    int length = getLength(head);

    if(position <= 1) {
       insertionAtHead(head, tail, data);
    }

    else if(position > length + 1) {
        cout << "Cannot Insert, invalid postion" << endl;
        return;
    }

    else if(position == length + 1) {
        insertionAtTail(head, tail, data);
    }

    else{   //INSERT AT MIDDLE OF LINKED LIST

        //Step 1: create a new node
        Node* newNode = new Node(data);

        //Step 2: traverse prev / curr to postion  
        Node* prev = NULL;
        Node* curr = head;
        while(position != 1) {
            position --;
            prev = curr;
            curr = curr->next;
        }
        //Step 3
        newNode-> next = curr;
        //Step 4
        prev-> next = newNode;
    }
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

    // Insert new node at head
    insertionAtHead(head, tail, 5);
    cout << "After inserting 5 at head: " << endl;
    printLL(head);
    cout << endl;

    // Insert new node at tail
    insertionAtTail(head, tail, 60);
    cout << "After inserting 60 at tail: " << endl;
    printLL(head);
    cout << endl;

    // Insert at position
    insertAtPosition(head, tail, 25, 4);
    cout << "After inserting 25 at position 4: " << endl;
    printLL(head);
    cout << endl;

    return 0;
}
