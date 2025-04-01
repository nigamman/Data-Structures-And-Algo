#include <iostream>
#include <limits.h>
using namespace std;

// //call an array using a function 

// void printArray (int arr[], int size) {
//     //int n = 6;
//     for(int i =0; i<size; i++) {
//         cout << arr[i] << " "; 
//     }      
// }
// int main () {
//    int arr[8] = {2,4,7,8,10,12,14,15};
//    int size = 8;
//    printArray (arr,size);

//    return 0;          
// }

// // linear search in an array using functions

// bool linearSearch (int arr[], int size, int target) {
//     for(int i=0; i<size; i++) {

//         if(arr[i] == target) {
//             cout << "Target found" << endl;
//             return true;
//         }
//     }
//     cout << "Target not found" << endl;
//     return false;
// }
// int main () {
//     int arr [4] = {12,45,2,4};
//     int size = 4;
//     int target = 22;
//     //ANSWER STORE IN FOUND
//     bool found = linearSearch(arr, size, target);

//     return 0;
// }

// // Count Zero's and One's in an array using functions

// void countZeroOne (int arr[], int size) {
//     int zeroCount = 0;
//     int oneCount = 0;

//     for (int i=0; i<size; i++) {
//         if (arr[i]==0) {
//             zeroCount++;
//         }
//         if (arr[i]==1) {
//             oneCount++;
//         }
//     }
//     cout << "Zero Count: " << zeroCount << endl;
//     cout << "One Count: " << oneCount << endl;
// }
// int main () {
//     int arr[] = {0,0,1,1,0,1};
//     int size = 6;
//     countZeroOne(arr,size);

//     return 0;
// }

// //find min/max no in an array

// int findMinimumInAnArray(int arr[], int size) {
//     int minAns = INT_MAX;
//     for (int i=0; i<size; i++) {
//         minAns = min (arr[i], minAns);
//     }
//     return minAns;
// }
// int main () {
//     int arr[] = {12,34,6,45,46,-2};
//     int size = 6;

//     int minimum = findMinimumInAnArray(arr,size);
//     cout << "Minimum number in an array: " << minimum;

//     return 0;
// }

//REVERSE AN ARRAY

// void reverseArray(int arr[], int size) {

//     int left = 0;
//     int right = size-1;
//     while (left <= right) {
//         swap (arr[left], arr[right]);
//         left++;
//         right--;
//     }
//     //Printing the array
//     for (int i=0; i<size; i++) {
//         cout << arr[i] << " ";
//     }
// }

// int main () {
//     int arr[] = {10,20,30,40,50,60,70};
//     int size = 7;
//     cout << "Reversing Your Array" << endl;
//     reverseArray(arr,size);

// }

void extremePrint (int arr[], int size) {
    int left = 0;
    int right = size - 1;

        while (left <= right) {
            cout << arr[left] << endl;
            cout << arr[right] << endl;
            left ++;
            right --;
        }
}
int main () {
    int arr[7] = {10,20,30,40,50,60};
    int size = 6;
    extremePrint (arr,size);
    return 0;
}