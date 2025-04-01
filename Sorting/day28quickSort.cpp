#include <iostream> 
using namespace std;

void quickSort(int arr[], int start, int end) {
    
    if(start >= end) {
        return;     //base case
    }
    int i = start - 1;
    int j = start;
    int pivot = end;;

    while (j < pivot) {
        if(arr[j] < arr[pivot]) {
            i++;
            swap(arr[j],arr[i]);
        }
            j++;
    }
    i++;
    swap(arr[i], arr[pivot]);
    //recursive calls for left and right side 
    quickSort(arr,start,i-1); //i pe sorted element aa gaya hai that's why start to uss element (i) k phele tk select karenge
    quickSort(arr,i+1,end);   // aur isme uss element aka i k aage se end tk select karnege.
}

int main () {
    int arr[] = {7,2,1,8,6,3,5,4};
    int n = 8;
    quickSort(arr,0,7);    

    for(auto nums: arr) {
        cout << nums << " ";     
    } 
    cout << endl;
} 