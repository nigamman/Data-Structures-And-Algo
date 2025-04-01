#include <iostream>
#include <climits>
#include <vector>
using namespace std;

 // void printArray(int arr[], int size, int index) {
    //     if(index >= size) {   //base address
    //         return;
    //     }
    //     printArray(arr, size, index+1);  //recursion calls

    //     cout << arr[index] << " ";       //processing
    // }
    // int main () {
    //     int arr[] = {10,20,30,40,50};  //execution
    //     int size = 5;
    //     int index = 0;
    //     printArray(arr,size,index);
    // }

// bool searchTarget(int arr[], int size, int index, int target) {  
//     if (index >= size) { // baase case
//     return false;
//     }
//     if (arr[index] == target) {
//     return true;
//     }
//     bool recAns = searchTarget(arr, size, index + 1, target);  // recursion calls
//     return recAns;
// }
// int main () {
//     int arr[] = {10,20,30,40,50};
//     int size = 5;
//     int target = 17;
//     int index = 0;
//     cout << searchTarget(arr, size, index, target);
// }

// int findMin(int arr[], int size, int index, int &mini) {
//     if(index >= size) {
//         return 0;
//     }
//     mini = min(mini,arr[index]);

//     int ans = findMin(arr, size, index + 1, mini);
//     return ans;
// }

// int main () {
//     int arr[] = {10,23,3,35,53};
//     int size = 5;
//     int index = 0;
//     int mini = INT_MAX;
//     findMin(arr, size, index, mini);
//     cout << mini << endl; 
// }

// int storeEven(int arr[], int size, int index, vector<int> &ans) {
//    if(index >= size) {    //base case
//         return 0;
//    }
//    if(arr[index] % 2 == 0) {
//         ans.push_back(arr[index]);    //processing
//    }
//    int rec = storeEven(arr,size,index+1,ans);
//    return rec;  
// }

// int main () {
//     int arr[] = {23,37,54,77,74};
//     int size = 5;
//     int index = 0;
//     vector<int> ans;    
//     storeEven(arr,size,index,ans);
//  // printing array with each loop
//     for(auto nums: ans) {
//         cout << nums << " " << endl;
//     }
// }

// void doubleArray(int arr[], int size, int index, vector<int> &ans) {
//     if(index >= size) {
//         return;
//     }

//     ans.push_back(2 * arr[index]);
           
//     doubleArray(arr, size, index + 1, ans);
// }

// int main () {
//     int arr[] = {10,20,30,40,50};
//     int size = 5;
//     int index = 0;
//     vector<int> ans;
//     doubleArray(arr,size,index,ans);

//     for(auto nums: ans) {
//         cout << nums << " ";
//     }
//     cout << endl;
// }

// int findMax(int arr[], int size, int index, int &maxi) {
//     if(index >= size) {
//         return 0;
//     }
//     maxi = max(maxi,arr[index]);

//     int ans = findMax(arr, size, index + 1, maxi);
//     return ans;
// }

// int main () {
//     int arr[] = {10,23,3,35,53};
//     int size = 5;
//     int index = 0;
//     int maxi = INT_MIN;
//     findMax(arr, size, index, maxi);
//     cout << maxi << endl; 
// }
void findTarget(int arr[],int size,int index,int target,vector<int> &ans) {
    if (index >= size) {
        return;
    }
    if(arr[index] == target) {
        ans.push_back(index);
    }
    findTarget(arr,size,index+1,target,ans);
}
int main () {
    int arr[] = {10,23,23,35,53};
    int size = 5;
    int index = 0;
    int target = 10;
    vector<int> ans;

    findTarget(arr,size,index,target,ans);

    for(auto nums: ans) {
        cout << nums << " ";
    }  
}