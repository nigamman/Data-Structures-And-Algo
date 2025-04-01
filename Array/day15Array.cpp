#include <iostream>
#include <algorithm>
using namespace std;

// void shiftNegativeOneSide(int arr[], int n) {
//     int j = 0;
//  // j --> memory block -> jaha pr main negative no.
//  // ko store kar sakta hun.

//     for(int index = 0; index<n; index++) {
//      //index -> entire array ko transverse karne k liye.
//         if(arr[index] < 0) {
//             swap(arr[index], arr[j]);
//             j++;
//         }
//     }
// }
// int main() {
//     int arr[] = {-23,-4,4,3,2,-20};
//     int n = 6;

//     shiftNegativeOneSide(arr,n);

//     // print 
//     cout << "Printing the array" << endl;
//     for(int i=0; i<n; i++) {
//         cout << arr[i] << " ";
//     }
// }

    void shiftPositiveOneSide(int arr[], int n) {
        int j = 0;

        for(int index = 0; index<n; index++) {
            if(arr[index] > 0) {
                swap(arr[index], arr[j]);
                j++;
            }
        }
    }
    int main () {
        int arr[] = {-21,12,-1,56,-76,23,-43};
        int n = 7;
        shiftPositiveOneSide(arr,n);

        cout<<"Printing the array" << endl;
        for(int i=0; i<n; i++) {
            cout << arr[i] << " ";
        }
    }


        


