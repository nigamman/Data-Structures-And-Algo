#include <iostream>
#include <vector>
using namespace std;

// // Find pivot index

// int findPivotIndex(vector<int> & arr) {
//     int start = 0;
//     int n = arr.size();
//     int end = n-1;
//     int mid = start + (end-start) / 2;

//     while (start <= end) {
//         //corner case
//         if (start == end) {
//             return start;
//         }

//         if (arr [mid] > arr[mid+1]) {
//             return mid;
//         }
//         else if (arr [mid] < arr[mid-1]) {
//             return mid-1;
//         }
//         else if (arr[start] > arr[mid]) {
//             end = mid - 1;
//         }
//         else {
//             start = mid + 1;
//         }
//         int mid = start + (end-start) / 2;    
//     }
//     return -1;
// }
// int main () {
//     vector <int> v;

//     v.push_back(12); 
//     v.push_back(14);
//     v.push_back(16);
//     v.push_back(2);
//     v.push_back(4);
//     v.push_back(6);
//     v.push_back(8);
//     v.push_back(10);
    
//     int pivotIndex = findPivotIndex(v);
//     cout << "Pivot Index is: " << pivotIndex << endl;
//     return 0;
// }

// Search In A Rotated And Sorted Array

int findPivotIndex(int arr, int n ) {
    int n = arr.size();
    int start = 0
    int end = n-1;
    int mid = start + (end - start)/2;

    while (start<=end) {
        if (arr[mid] > arr [mid+1]) {
            return arr[mid];
        }
        else if (arr[mid] < arr[mid+1]) {
            return arr[mid+1];
        }
        else if (arr[mid] < arr[start]) {
            end = mid - 1; // go to left side because start i greater than that's why pivot element is on left side 
        }
        else {
            start = mid + 1;
        }
        mid = start + (end-start) /2;
    }
    return -1;
}
int binarySearch (int arr, int start, int end, int target ) {
    int mid = start + (end - start) /2;

    while (start <= end) {
        if (arr[mid] == target) {
            return target;
        }
        else if (arr[mid] > target) {
            end = mid -1;
        }
        else if (arr[mid] < target) {
            start = mid + 1;
        }
    }
    return -1;
}
int main () {
    
}
