#include <iostream>
#include <stack>
using namespace std;

bool checkRedundant(string &str) {
    stack <char> st;
    
    for(int i=0; i<str.length(); i++) {
        char ch = str[i];

        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        }
        else if(ch == ')') {
            int operationCount = 0;
            
            while(!st.empty() && st.top() != '(') {
                char temp = st.top();
                if(temp == '+' || temp == '-' || temp == '*' || temp == '/' ) {
                    operationCount++;
                }
                st.pop();
            }
            //yaha pr app tabhi panchoge jab
            //aapke stack k top pr ek opeing bracket hoga
            st.pop();

            if(operationCount == 0) {
                return true;
            }
        }
    }
    // agar yahan tk pahncha hun to iska mtlb 
    //pakka brackets k beech mein opration mila hoga
    return false;
}
int main () {
    string str = "((a+b) * (b+c))";
    bool ans = checkRedundant(str);

    if (ans == true) {
        cout << "Redundant Bracket Present" << endl;
    }
    else {
        cout << "Redundant Bracket not present in the given equation" << endl;
    }
}
