#include <iostream>
using namespace std;

// int binarySearch (int arr[], int n, int target) {
//     int start = 0;
//     int end = n-1;
//     int mid = (start + end) / 2;

//     while (start<=end) {
//         //found
//         if(arr[mid] == target) {
//          return mid;  
//         }
//         //right mein jao
//         else if(target > arr[mid]) {
//             start = mid + 1; 
//             //start = mid - 1;
//         }
//         //left mein jao
//         else if(target < arr[mid]) {
//             end = mid - 1;
//             //end = mid + 1;
//         }
//         //update mid
//         mid = (start + end) / 2;
//     }
//     // agar yahan tk koi element nhi mila to return -1
//     return -1;
// }
// int main () {
//     int arr[] = {10,20,30,40,50,60,70,80,90};
//     int target = 50;
//     int n = sizeof(arr) / sizeof(arr[0]);

//     int ansIndex = binarySearch(arr, n, target);
        
//         if(ansIndex == -1) {
//             cout << "Element not found in the given array." << endl;
//         }
//         else {
//             cout << "Element found at : " << ansIndex << "th Index" << endl;
//         }
// }

// int findFirstOccurence(int arr[], int n, int target) {
//     int start = 0;
//     int end = n-1; 
//     int mid = start + (end-start) / 2; //best practice instead of s+e/2
//     int ans = -1;

//     while (start <= end) {
//         if (arr[mid] == target) {
//             ans = mid; 
//          //go to left side if found target on mid
//          end = mid - 1;
//         }
//         else if (target > arr[mid]) {
//             //go to right side of an array
//          start = mid + 1;
//         }
//         else if (target < arr[mid]) {
//             //go to left side of an array
//          end = mid - 1;
//         }
//         //update mid most imp
//         mid = start + (end-start) / 2; 
//     }
//      return ans;   
// }
// int main () {
//     int arr[] = {10,20,30,30,30,40,50};
//     int target = 30;
//     int n = sizeof(arr) / sizeof(arr[0]);

//     int ansIndex = findFirstOccurence(arr, n, target);

//     if (ansIndex == -1) {
//         cout << "Element not found in an given array" << endl;
//     }
//     else {
//         cout << "Fisrt Occurence of Element found at " << ansIndex << "nd Index"<< endl;
//     }
// }

// int findLastOccurence(int arr[], int n, int target) {
//     int start = 0;
//     int end = n-1;
//     int mid = (start + end) / 2;
//     int ans = -1;

//     while(start <= end) {
//         if (arr[mid] == target) {
//             ans = mid;
//             start = mid + 1; // because we are finding the last occurence that's why we go to right side.
//         }
//         else if (arr[mid] < target) {
//             start = mid + 1; //go to right side because target is greater then mid
//         }
//         else if (arr[mid] > target) {
//             end = mid - 1; //go to left side because target is less then mid
//         }
//         mid = (start + end) / 2;
//     }
// }
// int main () {
//     int arr[] = {10,20,30,30,30,40,50};
//     int target = 30;
//     int n = sizeof(arr) / sizeof(arr[0]);

//     int ansIndex = findLastOccurence(arr, n, target);

//     if (ansIndex == -1) {
//         cout << "Invalid Element" << endl;
//     }
//     else {
//         cout << "Last Occurence of Element found at " << ansIndex << "th Index" << endl;
//     }
// }

// int findTotalOcc(int arr[], int n, int target) {
//     int firstOcc = findFirstOccurence(arr, n, target);
//     int lastOcc = findLastOccurence(arr, n, target);
//     int total = lastOcc - firstOcc + 1;
//     return total;
// }
// int main () {
//     int arr[] = {10,20,30,30,30,30,40,50,60,70};
//     int target = 30;
//     int n = sizeof(arr) / sizeof(arr[0]);

//     int ansIndex = findTotalOcc(arr, n, target);
    
//     if(ansIndex == -1){
//         cout << "Invalid Element" << endl;
//     }
//     else{
//         cout << "total occurence of an element is " << ansIndex << endl;
//     }
// }

int findMissingElement(int arr[], int n) {
    int start = 0;
    int end = n-1;
    int mid = start + (end-start) / 2;
    int ans = -1;
    
    while (start <= end) {
         int diff = arr[mid] - mid;

     if(diff == 1) {
         start = mid + 1; // go to right side
        }
     else {
         ans = mid;
         end = mid - 1; // go to left side
         //ans = mid;
        }
     mid = start + (end-start) / 2;
    }
    return ans + 1;
}
int main () {
    int arr[] = {1,2,3,4,5,7,8,9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int ansIndex = findMissingElement(arr,n);

    cout << "Missing Element Is: " << ansIndex << endl; 
}