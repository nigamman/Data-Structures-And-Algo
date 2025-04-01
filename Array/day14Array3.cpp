#include <iostream>
using namespace std;

//  void printArray(int arr[][4], int row, int col) {
        
//         for(int i=0; i<row; i++) {
//             for(int j=0; j<col; j++) {     
//                 cout << arr [i][j] << " ";
//             }           
//             cout << endl;
//         }
//     }

//     void colWisePrint(int arr[][4], int row, int col) {
//         for(int i=0; i<col; i++) {
//             for (int j=0; j<row; j++) {
//                 cout << arr[j][i] << " "; 
//             }
//             cout << endl;
//         }
//     }
    void roWiseSum(int arr[][4], int row, int col) {
        for(int i=0; i<row; i++) {
            int sum = 0; 
                for(int j=0; j<col; j++) {
                    sum = arr[i][j];
                }
                cout << sum << endl;
        }
    }

    void colWiseSum(int arr[][4], int row, int col) {
        for(int i=0; i<col; i++) {
            int sum = 0;

            for(int j=0; j<row; j++) {
                sum = sum + arr[j][i];
            }
          cout << sum << endl;
        }
    }
int main () {

int arr [3][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,0,1,2}
    };  
        int row = 3;
        int col = 4;
        roWiseSum(arr,row,col);
        colWiseSum(arr,row,col);

        // printArray(arr,row,col);
        // colWisePrint(arr,row,col);


 //Create 2D array:
    // int arr [3][4];
    // return 0;

 //Initialise 2D Array
    // int brr [3][4] = {
    //     {1,2,3,4},
    //     {5,6,7,8},
    //     {9,10,11,12}
    // };
//  //Row Not Given
//     int crr [][4] = {
//         {1,2,3,4},
//         {5,6,7,8},
//         {9,10,11,12}
//     };
//  //Column Not Given (but column is necessary to give)
//     int brr [3][] = {
//         {1,2,3,4},
//         {5,6,7,8},
//         {9,10,11,12}
//     };
//  //Row and column both are not given
//     int drr [][] = {
//         {1,2,3,4},
//         {5,6,7,8},
//         {9,10,11,12}
//     };

 }