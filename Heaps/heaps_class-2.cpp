#include <iostream>
#include <queue>
using namespace std;

int kthSmallest (int arr[], int l, int r, int k) {
    
    priority_queue<int>maxHeap;

    //step1- first push k elements in the maxHeap
    for(int i=l; i<k; i++) {
        maxHeap.push(arr[i]);
    }

    //step2- after pushing k elements, comparing the values of max heap top element and arr[i] element and push the smallest element
    for(int i=k; i<=r; i++) {
        if(maxHeap.top() > arr[i]) {
            maxHeap.pop();
            maxHeap.push(arr[i]);
        }
    }
    return maxHeap.top();
}

int main () {

   int arr[] = {12,34,5,2,12,43,1};
   

}