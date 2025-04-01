#include <iostream>
using namespace std;

// int main () {
//     int a = 5;
//     cout <<"Value of a "<< a << endl;
//     cout << "Address of a " << &a << endl;
    
//     //creating pointers
//     int *ptr = &a;
//     //accessing value stored at address in ptr
//     cout << ptr << endl;
//     //Accessing wo element print hoga jiska address ptr ne save kiya hai
//     cout << *ptr << endl;
//     //iss ptr k khud ka address print hoga
//     cout << &ptr << endl;
//     // print size of ptr
//     cout << sizeof(ptr) << endl;
//     //
//     cout << *a << endl;
// }

void solve(int arr[], int size) {
    cout << "Size of array inside fxn: " << sizeof(arr) << endl;
    cout << "Inside Fxn -> arr: "<< arr << endl;
    cout << "Inside Fxn -> &arr: " << &arr << endl;
}
 int main () {
    int arr[] = {10,20,30,40,50};
    cout << "Size Of Array: " << sizeof(arr) << endl;
   
    solve (arr,5);
    cout << "Inside main -> arr: " << arr << endl;
    cout << "Inside main -> &arr: " << &arr << endl;

    // int brr[5] = {1,2,3,4,5};
    // //pointer to an array
    // int* ptr1 = brr;
    // //pointer to an array
    // int (*ptr)[5] = &brr ;

}