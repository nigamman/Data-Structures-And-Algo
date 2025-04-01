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
        if((rear + 1) % size == front) {
            cout << "Overflow" << endl;
        }
        //check empty case
        else if(front == -1 && rear == -1){
            front++;
            rear++;
            arr[rear] = val;
        }
        //circular case
        else if(rear == size - 1 && front != 0) {
            rear = 0;
            arr[rear] = val;
        }
        //normal case
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
        //circular case
        else if(front == size - 1) {
            arr[front] = -1;
            front = 0;
        }
        //normal case
        else{
            arr[front] = -1;
            front++;
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
    void print() {
        cout << "Printing Circular Queue: " << endl;
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

    q.print();
    q.pop();
    q.print();
    q.push(19);
    q.print();

}   