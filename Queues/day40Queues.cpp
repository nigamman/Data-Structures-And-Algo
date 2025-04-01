#include<iostream>
using namespace std;

class Queue {
    public:
        int *arr;
        int size;
        int front;
        int rear;

    Queue(int size) {
        arr = new int[size];
        this -> size = size;
        front = -1;
        rear = -1;
    }
    void push(int val) {
        //overflow case
        if(rear == size-1) {
            cout << "Overflow" << endl;
        }
        //check empty case
        else if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[rear] = val;
        }
        else{
            rear++;
            arr[rear] =val;
        }
    }
    void pop() {
        //underflow case
        if(front == -1 && rear == -1) {
            cout << "Queue is Empty" << endl;
        }
        // single elemet
        else if(front == rear) {
            arr[front] = -1;
            rear = -1;
            front = -1;
        }
        else{
            arr[front] = -1;
            front++;
        }
    }
    int getFront() {
        if(front == -1) {
            cout << "Queue is Empty" << endl;
        }
        else {
            return arr[front];
        }
    }
    int getRear() {
        if(rear == -1) {
            cout << "Queue is Empty" << endl;
        }
        else {
            return arr[rear];
        }
    }
    int getSize() {
        if(rear == -1 && front == -1 ) {
            return 0;
        }
        else {
            return rear-front+1;
        }    
    }
    bool isEmpty() {
        if(front == -1 && rear == -1) {
            return true;
        }
        else {
            return false;
        }
    }
    void print() {
        cout << "Printing Queue: " << endl;
        for(int i=0; i<size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main () {
    Queue q(5);

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    cout << "Size of the Queue is: " << q.getSize() << endl;
    
    q.print();
    cout << "Front Element: " << q.getFront() << endl;

    q.pop();

    q.print();

    cout << "Size of the Queue is: " << q.getSize() << endl;

    cout << "Queue is empty: " << q.isEmpty() << endl;
    cout << "Front Element: " << q.getFront() << endl;
    cout << "Rear Element: " << q.getRear() << endl;
    
    q.push(10);

}