#include <iostream>
#include <vector>
using namespace std;

// void function (int arr[], int n) {
   
//     cout << "Printing Array" << endl;
    
//     for (int i=0; i<n; i++) {
//         cout << arr[i] << endl;
//     }
// }

// int main () {
//  //Static Array
//     // int arr[] = {12,12,12,12,21};
//     // int n = 5;
//     // function(arr ,n); 

//  //Dynamic Array
//   int n;
//     cin >> n;
//   int * arr = new int[n];
//     for(int i=0; i<n; i++) {
//         int data;
//          cin >> data;
//         arr[i] = data;
//     }

//     function(arr,n);
// }

void print(vector <int> v) {
   int size = v.size();
    cout << "Printing Vector" << endl;
        for(int i=0; i<size; i++) {
         cout << v[i] << " ";
        }
    cout << endl;
} 

int main () {
   
   
//  //Advance Method To Print The Vector
//     vector<int> arr{12,13,14,15,16};
//     print (arr);
//     vector <int> arr1{10,11,12,13,14};
//     print (arr1);

//     vector <int> v;
//         v.push_back(1);
//         v.push_back(2);
//         v.push_back(3);
//         v.push_back(4);
//     print(v);

//  //v.pop_back();
//    v.clear();
//     print(v);

}