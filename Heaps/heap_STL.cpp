#include <iostream>
#include <queue>
using namespace std;

int main () {
    
    //creating max heap
    priority_queue<int> maxHeap;

    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(30);

    cout << maxHeap.top() << endl;

    maxHeap.pop();

    cout << maxHeap.top() << endl;

    cout << maxHeap.size() << endl;

    if(maxHeap.empty()) {
        cout << "Empty" << endl;
    }
    else {
        cout << "Non Empty" << endl;
    }
}