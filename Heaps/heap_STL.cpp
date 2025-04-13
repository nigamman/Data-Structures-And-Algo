#include <iostream>
#include <queue>
using namespace std;

int main () {
    
    //creating max heap
    priority_queue<int> maxHeap;

    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(30);

    cout << "top element of Max Heap: " << maxHeap.top() << endl;
    maxHeap.pop();
    cout << "top element of Max Heap: " << maxHeap.top() << endl;
    cout << "Size of Max Heap: " <<maxHeap.size() << endl;

    if(maxHeap.empty()) {
        cout << "Empty" << endl;
    }
    else {
        cout << "Non Empty" << endl;
    }

    //min-heap
    priority_queue<int,vector<int>, greater<int> > pq;
    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(4);
    pq.push(8);
    
    cout << "top element of Min Heap: " << pq.top() << endl;
    pq.pop();
        cout << "Size: " << pq.size() << endl;
        cout << "top element of Min Heap: " << pq.top() << endl;
    pq.pop();
        cout << "top element of Min Heap: " << pq.top() << endl;
    pq.pop();
        cout << "top element of Min Heap: " << pq.top() << endl;
    pq.pop();
        cout << "top element of Min Heap: " << pq.top() << endl;
    pq.pop();
    
    if(pq.empty()) {
        cout << "Min heap is empty" << endl;
    }
    else {
        cout << "Min heap is not empty" << endl;
    }
    return 0;
}