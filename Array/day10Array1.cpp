#include <iostream>
using namespace std;

int main () {
//     int arr [10];

//     //to find address of array
//     cout << "Address of array: "<< & arr << endl;

//     // to find size of an array
//     cout << sizeof(arr);

//     //Index value not aasign elements equal to index value
//     int brr [] = {12,4,6,5};

//     // Index value is equal to the elements
//     int crr [4] = {12,4,2,4};

//     //This will show error bcoz index value is less and elements are more.
//     //int drr [2] = {45,32,5,3};

//     //This will not show error bcoz index value is greater than elements, in empty place zero will be stored.
//     int err [5] = {5,7,76};

//     int srr [4] = {2,41,5,34};
    
//     cout << srr[2] << endl;
//     cout << srr[3] << endl;
    
//     int arr[3] = {12,43,45};

//     int n = 3;
//     for(int i=0; i<n; i++) {
//         cout << arr[i] << " ";

//     }

//     int arr[5];

//     int n = 5;
//     for(int i=0; i<n; i++) {
//         cout <<"Enter the value of index" << i <<" ";
//         cin >> arr[i];
//         cout << endl;
//     }

//     cout << "Printing the array" << endl;

//     for (int i=0; i<n; i++) {
//         cout << arr[i] << " ";
//     }


//     int arr[10];

//     int n=10;
//     for(int i=0; i<10; i++) {
//        cout << arr[i] << " ";
//        cin >> arr[i];
//         arr[i] = 2 * arr[i]; 

//         cout << arr[i];
//     }

// //Taking input the array from user
//     int arr[5];
//     int n =5;
//     cout << "Enter the input"<< endl;
//     for(int i=0; i<n; i++) {
//         cin >> arr[i];
//     }

// //sum of their array 
//     int sum = 0;
//     for(int i=0; i<n; i++) {
//         sum += arr[i];
//     }
//     cout << "Printing the sum: " << sum << endl;

// }

int arr[5] = {23,2,3,5,4};
int n = 5;
bool flag = 0;

int target;
cout << "Enter the target" << endl;
cin >> target;

//target found --> 1
//target not found --> 0

for(int i=0; i<n; i++) {

    if(arr[i]==target) {
        flag = 1;
        cout << "Target found" << endl;
        break;
    }
    else {
        cout << "Target not found" << endl;
    }
    return 0;
 }
}
