#include <iostream>
using namespace std;

class heap {
public:
    int* arr;
    int size;
    int capacity;

    heap(int capacity) {
        this->arr = new int[capacity]; 
        this->size = 0;
        this->capacity = capacity;
    }

    void insertionInHeap(int val) {
        if(size == capacity) {
            cout << "Heap Overflow" << endl;
            return;
        }
        size++;
        int index = size;
        arr[index] = val;

        // Up-heapify
        while(index > 1) {
            int parentIndex = index / 2;
            if(arr[index] > arr[parentIndex]) {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else {
                break;
            }
        }
    }

    int getSize() {
        return size;
    }

    int getElement(int index) {
        return arr[index];
    }

    void printHeap() {
        for(int i=1; i<=size; i++) {
           cout << arr[i] << " ";
        }
    }

    int deletionInHeap(){
        int answer = arr[1];
        //replacement
        arr[1] =  arr[size];
        //last element ko delete uski original postion se
        size--;
        int index = 1;
        while(index < size) {
            int leftIndex = 2* index;
            int rightIndex = 2* index +1; 
            int largestIndex = index ; // to find out which is the largest index

            if(leftIndex <= size  && arr[leftIndex] > arr[largestIndex]) {
                largestIndex = leftIndex;
            } 
            if(rightIndex <= size && arr[rightIndex] > arr[largestIndex]) {
                largestIndex = rightIndex;
            }
            if(index == largestIndex) {
                break;
            }
            else {
                swap(arr[index], arr[largestIndex]);
                index = largestIndex;
            }
        }
        return answer;
    }
};

void heapify(int *arr, int n, int index) {
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;
    int largestIndex = index;

    if(leftIndex <= n && arr[leftIndex] > arr[largestIndex]) {
        largestIndex = leftIndex;
    }
    if(rightIndex <= n && arr[rightIndex] > arr[largestIndex]) {
        largestIndex = rightIndex;
    }
    if (index != largestIndex) {
        swap(arr[index], arr[largestIndex]);
    
        //ab recursion sambhalega
        index = largestIndex;
        heapify(arr,n,index);
    }
}
void buildHeap(int arr[], int n) {
    for(int index = n/2; index > 0; index--) {
        heapify(arr,n,index);
    }
}
void heapSort(int arr[], int n) {
    while(n != 1) {
        swap(arr[1], arr[n]);
        n--;
        heapify(arr,n,1);
    }
}

int main() {

    int arr[] = {-1,5,10,15,20,25,12};
    int n = 6;
    buildHeap(arr,6);

    cout << "printing heap: " << endl;
    for(int i=1; i<=6; i++) {
    cout << arr[i] << " ";
    }
    cout << endl;

    heapSort(arr, n);
    cout << "printing sorted heap: " << endl;
    for(int i=1; i<=6; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    // heap h(10);
    // h.insertionInHeap(5);
    // h.insertionInHeap(10);
    // h.insertionInHeap(15);
    // h.insertionInHeap(6);
    // h.insertionInHeap(25);
    // h.insertionInHeap(50);

    // // cout << "Printing the content of heap: " << endl;
    // // h.printHeap();

    // int ans = h.deletionInHeap();
    // cout << "Answer: " << ans << endl;
    
    // cout << "Printing the content of heap: " << endl;
    // h.printHeap();

}
