#include <iostream>
#include <limits.h>

using namespace std; 

// bool findTarget(int arr[][4], int row, int col, int target) {
//     for(int i=0; i<row; i++) {
//         for{int j=0; j<col; j++} {
//             if (arr[i][j] == target) {
//               return true;
//             }
//         }
//     }
//     return false;
// }

// int findMax(int arr[][4], int row, int col) {

//     int maxAns = INT_MIN;

//     for(int i=0; i<row; i++) {
//         for(int j=0; j<col; j++) {
//             if (arr[i][j] > maxAns) {
//                 maxAns = arr [i][j];
//             }
//         }
//     }
//     return maxAns;
// }

void printArray(int arr[][4], int row, int col) {
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {   
            cout << arr[i][j] << " ";
        }           
        cout << endl;
    }
}

void transpose(int arr[][4], int row, int col) {
    for(int i=0; i<row; i++) {
        for(int j=i; j<col; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }
}

int main () {
    int arr[3][4] = {
        {12,13,13,14},
        {10,34,25,65}, 
        {33,65,58,43}
    };
    int row = 3;
    int col = 4;

    cout << "Print Before Transpose" << endl;
    printArray(arr, row, col); 
    cout << "Print After Transpose"<< endl;
    transpose(arr, row, col);
    printArray(arr, col, row);



    //int target = 12;
    //cout << "Printing the max. no. " << findMax(arr,row,col) << endl;
    //cout << "found or not: " << findTarget(arr,row,col,target);

    return 0;
}