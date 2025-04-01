#include <iostream>
#include <queue>
using namespace std;

int main() {

    queue<int> q;

    //creation 
    q.push(10);

    //size checking
    cout << "Size of the Queue: " << q.size() << endl;

    if(q.empty() == true) {
        cout << "Queue is Empty" << endl;
    }
    else {
        cout << "Queue is Not Empty" << endl;
    }

    //pop
    q.pop();

    //size checking
    cout << "Size of the Queue: " << q.size() << endl;

    if(q.empty() == true) {
        cout << "Queue is Empty" << endl;
    }
    else {
        cout << "Queue is Not Empty" << endl;
    }

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front Element is: " << q.front() <<endl;
    cout << "Back Element is: " << q.back() <<endl;
    
}