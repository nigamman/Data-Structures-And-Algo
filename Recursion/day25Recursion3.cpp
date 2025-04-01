#include <iostream>
#include <vector>
using namespace std;

// bool isSorted(int arr[], int size, int index) {

//     if(index >= size) { //base case
//         return true;
//     }
//     if (arr[index] > arr[index+1]) {    //processing
//         bool recAns = isSorted(arr, size, index+1);  //recursion call
//         return recAns;          //return recursion answer
//     }
//     else {
//         return false;  //this means it is not sorted
//     }
// }
// int main () {
//     int arr[] = {10,20,60,40,50};
//     int size = 5;
//     int index = 0;

//     bool checkSorted = isSorted(arr, size, index);

//     if (checkSorted) {
//         cout << "Sorted Array" << endl;
//     }
//     else {
//         cout << "Not Sorted Array" << endl;
//     }
// }

// int binSearch(int arr[], int s, int e, int target) {
    
//     if(s > e) {
//         return -1;
//     }
//     int mid = s + (e-s)/2; 

//     if(arr[mid] == target) {
//         return mid;
//     }
//     if(arr[mid] > target) {
//         return binSearch(arr, s, mid - 1, target);  //left mein jao target bada hai
//     }
//     else(arr[mid] < target); {
//         return binSearch(arr, mid + 1, e, target);  // right mein jao target choota hai
//     }
// }
// int main() {
//     int arr[] = {10,20,30,40,50};
//     int size = 8;
//     int s = 0;
//     int e = size - 1;
//     int target = 30;
//     int found = binSearch(arr,s,e,target);

//     if(found != -1) {
//         cout << "Target Found at Index: " << found << endl; 
//     }
//     else{
//         cout << "Target not found" << endl;
//     }
// }
void findSubstring(string str, string output, int index, vector<string> &ans) {
    
    if(index >= str.length()) {
        ans.push_back(output);    // output jo char aayega usko pel denge ans string mein
        return;
    }
 // get the current from the string
    char ch = str[index];

    //ya to exclude hoga 
    findSubstring(str,output,index +1,ans);

    //ya to include hoga
    //jo ch hoga usko output mein pel denge

    output.push_back(ch);
    findSubstring(str,output,index +1,ans);
}
int main () {
    string str = "abc";
    int index = 0;
    string output = "";
    vector<string> ans;

    findSubstring(str,output,index,ans);

    for(auto finalAns: ans) {
        cout << "-> " << finalAns <<endl;
    }
}
