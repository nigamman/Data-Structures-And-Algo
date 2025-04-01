#include <iostream>
using namespace std;

class Node {
    public:
     int data;
      Node *prev = NULL;
      Node *next = NULL;
    Node () {
        this->prev = NULL;
        this->next = NULL;
    }
    Node (int data) {
        this->data = data;
        this->prev = NULL;
        this->next  = NULL;
    }
};

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << "-> ";
        temp = temp -> next;
    }
    cout << "NULL" <<endl;
}
int findLength(Node* head) {
    int len = 0;
    Node* temp = head;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}
void deleteNode(Node* &head, Node* &tail, int position) {
    if(head==NULL) {
        cout <<"empty Linked List" << endl;
        return;
    }
    if(head == tail) {
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }

    int length = findLength(head);
    if(position==1) {       //Delete headNode
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }
    else if(position == length) {    //delete tailNode
        Node* prevNode = tail->prev; 
        prevNode ->next = NULL;
        tail->prev = NULL;
        delete tail;
        tail = prevNode;
    }
    else {
       //step 1 set currNode/prevNOde/nextNode 
       Node* prevNode = NULL;
       Node* currNode = head;
      
        while (position != 1) {
            position--;
            prevNode = currNode;
            currNode = currNode-> next;
        }
        Node* nextNode = currNode ->next;

        prevNode->next = nextNode; 
        currNode->prev = NULL;
        currNode->next = NULL; 
        nextNode->prev = prevNode;
       
        delete currNode;
    }
}
void insertionAtHead(Node* &head, Node* &tail, int data) {

    if(head == NULL) {
        Node* newNode = new Node(data); 
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void insertionAtTail(Node* &head, Node* &tail, int data) {
    if(head == NULL) {
        Node* newNode = new Node(data); 
        head = newNode;
        tail = newNode;
    }
    else {
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        newNode = tail;
    }
}
void insertionAtPosition(Node* &head, Node* &tail, int data, int position) {
    if(position == 1) {
        Node* newNode = new Node(data); 
        head = newNode;
        tail = newNode;
    }
    int length = findLength(head);

    if(position == length + 1) {
        insertionAtTail(head, tail, data);
        return;
    }
    else if(position <= 1) {
        insertionAtHead(head, tail, data);
        return;
    }
    else {
        //Step 1 create new node
        Node* newNode = new Node(data);
        //Step 2 set prev and curr pointer
        Node* prevNode = NULL;
        Node* currNode = head;
        while(position != 1) {
            position--;
            prevNode = currNode;
            currNode = currNode -> next;
        }
        //step 3 update pointers
        prevNode->next = newNode;
        currNode->prev = newNode;
        newNode->next = currNode;
        newNode->prev = prevNode; 
    }
}

int main () {
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    first->next = second;
    second->prev = first;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;

    Node* head = first;
    Node* tail = fifth;

    cout << "Printing Original Linked List" << endl;
    print(head);
    cout << endl;

    // insertionAtHead(head, tail, 0);
    // cout << "Printing Updated Linked List after insertion at head" << endl;
    // print(head);

    // insertionAtTail(head,tail,60);
    // cout << "Printing Updated Linked List after insertion at tail" << endl;
    // print(head);

    // insertionAtPosition(head,tail,15,3);
    // cout << "Printing Updated Linked List after insertion at given position" << endl;
    // print(head);

    deleteNode(head, tail, 1);
    cout << "Given Node Deleted" << endl;
    print(head); 

    

}
