#include <iostream>
using namespace std;

// void printLine() {
//     for (int i=0; i<10; i++) {
//         cout << "10 lines" << endl;
//     }
// }
//     int main () {

//         printLine() ;

//     }

//USE OF VOID FUNCTION

// void printSum (int a, int b, int c) {
//     int answer = a+b+c;
//     cout << "sum is:" << answer;
// }

// int main () {
//     printSum (23,45,434);
// }

// Use of Return type function

int printSum (int a, int b, int c) {
    int answer = a+b+c;
    return answer;
}

int main () {
    int sum = printSum(12,23,34);
    cout << "sum is: "<< sum << endl;
}