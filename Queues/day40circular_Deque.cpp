#include<iostream>
using namespace std;

class Deque{
    public:
        int *arr;
        int front;
        int rear;
        int size;

    Deque(int size) {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void print() {
        for(int i = 0; i < size; i++) {
            cout << arr[i] << " "; 
        }
        cout << endl;
    }

    int getSize() {
        if(rear == -1 && front == -1 ) {
            return 0;
        }
        return rear - front + 1;
    }

    void pushBack(int val) {
        // empty case
        if(front == -1 && rear == -1) {
            front = 0;
            rear = 0;
            arr[rear] = val;
        }
        // overflow case
        else if((front == 0 && rear == size-1) || (rear + 1 == front)) {
            cout << "Overflow" << endl;
        }
        // circular deque case
        else if(rear == size - 1 && front != 0) {
            rear = 0;
            arr[rear] = val;
        }
        // normal case
        else {
            rear++;
            arr[rear] = val;
        }
    }

    void popBack() {
        // underflow
        if(front == -1 && rear == -1) {
            cout << "Queue underflow" << endl;
        }
        // single element
        else if(front == rear) {
            arr[rear] = -1;
            front = rear = -1;
        } 
        // circular case
        else if(rear == 0) {
            arr[rear] = -1;
            rear = size - 1;
        }
        // normal case
        else {
            arr[rear] = -1;
            rear--;
        }
    }

    void pushFront(int val) {
        // empty case
        if(front == -1 && rear == -1) {
            front = 0;
            rear = 0;
            arr[front] = val;
        } 
        // overflow
        else if((front == 0 && rear == size-1) || (front - rear == 1)) {
            cout << "Overflow" << endl;
        }
        // circular deque case
        else if(front == 0 && rear != size -1) {
            front = size -1;
            arr[front] = val;
        }
        // normal case
        else {
            front--;
            arr[front] = val;
        }
    }

    void popFront() {
        // underflow
        if(front == -1 && rear == -1) {
            cout << "Queue underflow" << endl;
        }
        // single element
        else if(front == rear) {
            arr[front] = -1;
            front = rear = -1;
        } 
        // circular case
        else if(front == size - 1) {
            arr[front] = -1;
            front = 0;
        }
        // normal case
        else {
            arr[front] = -1;
            front++;
        }
    }
};

int main () {
    Deque dq(5);

    dq.pushBack(10);
    dq.pushBack(20);  
    dq.pushFront(30);
    dq.pushFront(40);
    dq.pushBack(50);

    dq.popFront();

    dq.pushFront(11);
    dq.pushFront(21);
    


    dq.print();  // Check the elements inside the deque

    return 0;
}
