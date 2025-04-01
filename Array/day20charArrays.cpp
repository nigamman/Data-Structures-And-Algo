#include <iostream>
#include <string.h>
using namespace std;

//int main() {

    // //creation
    //char ch [5];
    

    // //input 
    // cin >> ch;
    // cin.getline(ch,100); // use this function to input whole sentence
    //out << "Length of an array " << strlen(ch) << endl; // use this fxn (strlen) to get length of a string

    //print
    // cout << "Printing the value of ch: " << ch <<  endl;

    // //printing every index using loops
    // for(int i=0; i<8; i++) {
    //     cout << "At Index" << i << " " <<ch[i] << endl;
    // }
    // // print ascii value at index

    // char temp = ch[5];
    // int value = (int) temp;
    // cout << "Printing ascii int value: " << value << endl;
//}

// void reverseOfString (char ch[], int n) {
//     int i = 0;
//     int j = n-1;

//     while(i<=j) {
//         swap(ch[i],ch[j]);
//         i++;
//         j--;
//     }
// }
// int main () { 

//     char ch[100];

//        //INPUT
//     cin.getline(ch,100);

//     cout << "Before " << ch << endl;

//     //use strlen(ch) to give length.
//     reverseOfString(ch,strlen(ch));

//     cout << "After  " << ch << endl;
// }

// void convertToUpperCase(char ch[], int n) {
//     int index = 0;

//     while (ch[index] != '\0') {
//      // check if the element in lower case,
//         if (ch[index] >= 'a' && ch[index <= 'z']) {

//          //convert into upper case
//            ch[index] = ch[index] - 'a' + 'A';
//         }
//         index++;
//     }   
// }

// int main () {
//     char ch[100];
//     cin.getline(ch,100);
//     cout << "Before: " << ch << endl;
//     convertToUpperCase(ch,100);
//     cout << "After: " << ch << endl;
// }

// // CHECK {PALINDROME} OR NOT ......
// bool checkPalindrome (char ch[], int n) {
//     int i = 0;
//     int j = n-1;
//     while (i<=j) {
//         if (ch[i] == ch[j]) {
//             i++;
//             j--;
//         }
//         else {
//             return false;
//         }
//     }
//     return true;
// }
// int main () {
//     char ch[100];
//     cin.getline(ch,100);

//     bool isPalindrome = checkPalindrome(ch, strlen(ch)); // Assign the return value to a variable
//     //bool checkPalindrome(ch, strlen(ch));

//     if (isPalindrome) {
//         cout << "Valid" << endl;
//     }
//     else {
//         cout << "InValid" << endl;
//     }
// }

// Replace @ with space
void replaceCharacter (char ch[], int n) {
    int index = 0;
    while (ch[index] != '\0') {
        if (ch[index] == '@') {
            ch[index] = ' '; //insert index
        }
        index++;
    }
}
int main () {
    char ch[10];
    cin.getline(ch,100);

    replaceCharacter(ch,100);

    cout << ch << endl;
}