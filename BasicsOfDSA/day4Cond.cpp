#include <iostream>
using namespace std;

int main () {
    int num = 23;

//     if (num > 0){
//         cout << "Number is positive";
//     }
//     else if(num < 0){
//         cout << "Number is negative";
//     }
//     else {
//         cout << "Number is zero";
//     }
   
    if (num % 2 == 0) {
        cout << "even";
    }

    else if (num % 2 != 0) {
        cout << "odd";
    }

    else {
        cout << "nothing";
    }
}