#include <iostream>
using namespace std;

int getUniqe (int arr[], int n) {
    int ans = 0;
                                        
    for(int i =0; i<n; i++) {
        ans = ans^arr[i];
    }
    return ans;
}
int main () {
    int arr[] = {12,12,10,10,3,31,4,5,5};
    int n = 9;

    int finalAns = getUniqe(arr, n);

    cout << "Unique No. In an array is: " << finalAns;
}                                                              

// int main () {
//     int arr[] = {10,20,30};
//     int n = 3;

//     for (int i=0; i<n; i++) {
//         for (int j=0; j<n; j++) {
//             cout << arr[i] << "," << arr[j] << endl;
//         } 
//     }
// } 

// int main () {
//     int arr[] = {1,2,3,4};
//     int n = 4;

//     for(int i=0; i<n; i++) {
//         for(int j=0; j<n; j++) {
//             for (int k=0; k<n; k++) {
//                 cout << arr[i] << "," << arr[j] << "," << arr[k] << endl;
//             }
//         }
//     }
// }

// void sortZeroOne(int arr[], int n) {
//     int oneCount=0;
//     int zeroCount=0;

//  //Step1: count zero's and one's
//     for(int i=0; i<n; i++) {
//         if(arr[i] ==1) 
//             oneCount++;
//         if(arr[i] ==0) 
//             zeroCount++;
//     }

//     //  //Step2: place all zero's first
//     //     int i;
//     //     for(i=0; i<zeroCount; i++) {
//     //         arr[i] = 0;
//     //     }
//     //  //Step2.1: place all one's first
//     //     for(int j=i; j<n; j++) {
//     //         arr[j] = 1;
//     //     }
//     // }
           
//     // Easy Method of Step 2
//  int index =0;

//     while(zeroCount--) {
//         arr[index] = 0;
//         index++;
//     }
//     while(oneCount--) {
//         arr[index] = 1;
//         index++;
//     }
// }
// //Step3: Printing the array
//     int main () {
//         int arr[] = {1,0,0,0,1,1,1,0,1,0,1,0};
//         int n = 12;

//         sortZeroOne(arr,n);
//         for(int i=0; i<n; i++) {
//             cout << arr[i] << " " ;
//         }
//     }

// void rightShiftArray(int arr[], int n) {

//  //Step 1 save value of last index
//     int temp = arr[n-1];

//  //Step 2 shift --> arr[i] = arr[i-1] 
//     for (int i= n-1; i>= 1; i--) {
//         arr[i] = arr[i-1];
//     }

//  //Step 3 copy the value of 0th index 
//     arr[0] = temp;
// }

// int main () {
//     int arr[] = {10,20,30,40,50,60};
//     int n = 6;
//     rightShiftArray(arr,n);

//     for (int i=0; i<n; i++) {
//         cout << arr[i] << " ";
//     }
// }

