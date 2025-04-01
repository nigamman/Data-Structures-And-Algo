include <iostream>
using namespace std;

class Stack{
    public:
        int* arr;
        int size;
        int top;
    
        // Constructor
        Stack (int size) {
            arr = new int [size];
            this-> size = size;
            this-> top = -1; 
        }
        // Destructor
         ~Stack() {
            delete[] arr;
        }
    
        //PUSH 
        void push(int data) {
            if(top == size -1) {
                cout << "Stack Overflow" << endl;
                return;
            }
            else {
                top++;
                arr[top] = data;
            }
        }
    
        //POP
        void pop() {
            if (top == -1) {
                cout << "Stack Underflow" << endl;
            }
            else {
                top--;
            }
        }
    
        //SIZE
        int getSize(){
            return top+1;
        }
    
        //FETCH TOP ELEMENT
        int getTop() {
            if(top == -1) {
                cout << "Stack is empty" << endl;
                return -1;
            }
            else {
                return arr[top];
            }
        }
    
        //Check If EMPTY OR not
        bool isEmpty() {
            if(top == -1) {
                return true;
            }
            else {
                return false;
            }
        }
        void print() {
            cout << "Top: " << top << endl;
            cout << "Top Element: " << getTop() << endl;
            cout << "Stack: ";
            for(int i=0; i < getSize(); i++) {
                cout << arr[i] << " ";
            }
            cout << endl << endl;
        }
    };
    int main () {
        
    }