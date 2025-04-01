#include<iostream>
#include<deque>
using namespace std;

int main () {

    deque<int> dq;

    dq.push_back(10);
    dq.push_back(20);  
    dq.push_front(30);
    dq.pop_front();

    if(!dq.empty()) {
        cout << "Front Element: "<< dq.front() << endl;
        cout << "Back Element: " << dq.back() << endl;
    }
    else{
        cout << "deque is empty no front and rear element" << endl;
    }
    

    if(dq.empty() == 0) {
        cout << "Given Deque is Not Empty" << endl;
    }
    else {
        cout << "Given Deques is Empty" << endl;
    }
}
