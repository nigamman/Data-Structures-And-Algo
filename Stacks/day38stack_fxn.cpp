#include<iostream>
#include<stack>
using namespace std;


void solve(stack<int> &st, int &pos, int &ans) {

    //base case 
    if(pos ==1){
        ans = st.top();
        return;
    }

    //1 case hum solve karenge
    pos--;
    int temp = st.top();
    st.pop();
    
    //Recursion
    solve(st,pos,ans);

    //backtrack
    st.push(temp);
}

int getMiddleElement(stack<int> &st) {
    int size = st.size();

    if(st.empty()) {
        cout << "Stack is empty, no middle element found" << endl;
        return -1;
    }
    else {
        //stack is not empty
        //for odd- postion
        int pos = 0;
        if(size & 1) {
            pos = size/2 + 1;
        }
        else {
            //for even position
            pos = size/2;
        }
        int ans = -1;
        solve(st, pos, ans);
        return ans;
    }

}

void insertAtBottom(stack<int> &st, int &element) {

    //base element
    if(st.empty()) {
        st.push(element);
        return;
    }

    //1 cae mein solve karunga
    int temp = st.top();
    st.pop();

    //recursion 
    insertAtBottom(st,element);

    //backtracking
    st.push(temp);
}

void reverseStack(stack<int> &st) {
    
    //base case
    if(st.empty()) {
        return;
    }

    //1st case main solve karunga
    int temp = st.top();
    st.pop();

    //then, recursion
    reverseStack(st);

    //backtrack
    insertAtBottom(st,temp);
}

void insertElemAtSorted(stack<int> &st, int element) {

    // base case 
    if(st.empty() || element > st.top()) {
        st.push(element);
        return;
    }

    //1 case sambhalna hai
    int temp = st.top();
    st.pop();

    //recursion
    insertElemAtSorted(st,element);

    //backtrack
    st.push(temp);
}

void sortStack(stack<int> &st) {

    //base case
    if(st.empty()) {
        return;
    }

    //1 case tum solve karo
    int temp = st.top();
    st.pop();

    //Recursion
    sortStack(st);

    //backtrack
    insertElemAtSorted(st, temp);
}


int main () {

    stack <int> st;
    st.push(10);
    st.push(90);
    st.push(30);
    st.push(21);


    //reverseStack(st);
    // cout << "reversed stack using recurion: " << endl;

    // insertAtBottom(st,element);

    //insertElemAtSorted(st,40);
    sortStack(st);

    while(!st.empty()) {
        cout<< st.top() << " ";
        st.pop();
    }

    // stack <int> st;
    // st.push(10);
    // st.push(20);
    // st.push(30);
    // st.push(40);
    // st.push(50);
    // int element = 100;


    // int mid = getMiddleElement(st);
    // cout << "Middle Element: " << mid << endl;

    // Stack st(8);

    // st.push(10);
    // st.push(20);
    // st.push(30);
    // st.print();

    // st.push(40);
    // st.push(50);
    // st.push(60);
    // st.print();

    // st.push(70);
    // st.push(80);
    // st.push(90);
    // st.print();

    // st.pop();
    // st.print();
    // cout << "Size of the stack: " << 
    // //creation
    // stack <int> st;

    // //insertion
    // st.push(10);
    // st.push(20);
    // st.push(30);

    // //size check
    // cout << "size of the stack: " << st.size() << endl;

    // //deletion
    // st.pop();

    // //check estack is empty or not 
    // if(st.empty()) {
    //     cout << "given stack is empty" << endl;
    // }
    // else{
    //     cout << "given stack is not empty" << endl;
    // }

    // //top element
    // cout << st.top() << endl;
}
