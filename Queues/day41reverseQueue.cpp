#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void reverseQueue(queue<int> &q) {
    stack <int> s;

    //transfer all element from queue to stack 
    while(!q.empty()) {
        int frontElement = q.front();
        q.pop();

        s.push(frontElement);
    }
    //now, transfer element from stack to queue
    while(!s.empty()) {
        int element = s.top();
        s.pop();

        q.push(element);
    }
}

void reverseUsingRecursion(queue<int> &q) {
    //base case 
    if(q.empty()) {
        return;
    }
    int element = q.front();
    q.pop();

    reverseUsingRecursion(q);

    q.push(element);
}

void reverseKelement(queue<int> &q, int k) {

    stack<int> s;
    int n = q.size();

    if (k > n || k == 0) {
        return;
    }
    //push first k elements into stack
    for(int i=0; i<k; i++) {
        int temp = q.front();
        q.pop();
        s.push(temp);
    }   
    //push all k elements into queue again
    while(!s.empty()) {
        int temp1 = s.top();
        s.pop();
        q.push(temp1);
    }
    //first pop, then push n-k elements into queue
    for(int i = 0; i < n-k; i++) {
        int temp2 = q.front();
        q.pop();
        q.push(temp2);
    }
    
}
void reverseInterLeaveQueue(queue<int> &first) {
    queue<int> second;
    int n = first.size();
    
    //break first queue into two halves first and second
    for(int i=0; i<n/2; i++) {

        int temp = first.front();
        first.pop();

        second.push(temp);
    }
    for(int i=0; i<n/2; i++) {

        //store second queue element in temp
        int temp = second.front();
        //then pop second queue element
        second.pop();
        //then push second element in the first queue
        first.push(temp);
        //then store first ke element in the temp
        temp = first.front();
        //then pop first ke element
        first.pop();
        //push first ke element in the second which is stored in temp
        first.push(temp);
    }
}

int main() {
    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    //reverseQueue(q);
    //reverseUsingRecursion(q);
    //reverseKelement(q,6);
    reverseInterLeaveQueue(q);

    cout << "printing queue: " << endl;
    while(!q.empty()) {
        int element = q.front();
        q.pop();
        cout << element << " ";
    }
    cout << endl;
}