#include <iostream>
using namespace std;

// int getQuotient(int divident, int divisor) {
//     int s = 0;
//     int e = divident;
//     int mid = s+(e-s)/2;
//     int ans = -1;

//     while (s<=e) {
//         if(mid * divisor == divident) {
//             return mid;
//         }
//         else if(mid * divisor < divident) {
//             ans = mid; //store the ans and go to right
//             s = mid + 1;
//         }
//         else{
//             e = mid -1;
//         }
//         mid = s + (e-s) /2;
//     }
//     return ans;
// }

// int main () {
//     int divident = 4;
//     int divisor = -2;
//     int ans = getQuotient(abs(divident), abs(divisor));

//     if(divident < 0 && divisor > 0 || divident > 0 && divisor < 0 ) {
//         ans = 0 - ans;
//     }
    
//     cout << "Final Ans Is: " << ans << endl;
// }

// int searchNearlySorted(int arr[], int n, int target) {
//     int s = 0;
//     int e = n-1;
//     int mid = s + (e-s)/2;

//     while(s<=e) {
//         if (mid == target) {
//             return mid;
//         }
//         else if (mid-1 >= 0 && arr[mid-1] == target) {
//             return mid-1;
//         }
//         else if (mid+1 < n && arr[mid+1] == target) {
//             return mid+1;
//         }
//         else if (target > arr[mid]) {
//             s = mid + 2; // isme -1 output de raha hai
//             //s = mid + 1 yeh kar rahe hain to error nhi aa rahi
//         }
//         else {
//             e = mid - 2;
//             //e = mid -1 same here
//         }
//         mid = s + (e-s)/2;
//     }
//     return -1;
// }
// int main () {

//     int arr[] = {30,15,60,45,90,105};
//     //int n = 6;
//     int ans = searchNearlySorted(arr,6,90);

//     cout << "Element at Index " << ans << endl;
// }

int findOddOccuringElement (int arr[], int n) {
    int s = 0;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<=e) {
        //single element
        if(s == e) {
            return s;
        }
    // check mid its even or odd
    // for odd element
        if(mid & 1) {
            if(mid-1 >= 0 && arr[mid] == arr[mid-1]) {
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }

    // for even element 
        else {
            if (mid+1 < n && arr[mid] == arr[mid+1]) {
                s = mid + 1;
            } 

            else {
        //ya toh main right part pr khada hu
        //ya toh main answer k upar khada hu
        //that's why e = mid krra hu
        // kyoki e = mid - 1; se ans lost ho skta h 
                e  = mid;
            }
        }
        mid = s + (e-s)/2;
    }
    return -1;
}
int main () {
    int arr[] = {10,10,2,2,5,5,4,3,3,1,1,6,6};
    int n = 13;
    int ans = findOddOccuringElement(arr,n);

    cout << "Odd Occuring Element is: " << arr[ans] << endl;
}