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
};

int main() {
    heap h(10);
    h.insertionInHeap(5);
    h.insertionInHeap(10);
    h.insertionInHeap(15);
    h.insertionInHeap(6);
    h.insertionInHeap(25);
    h.insertionInHeap(50);

    for(int i = 1; i <= h.getSize(); i++) {
        cout << h.getElement(i) << " ";
    }

    return 0;
}
