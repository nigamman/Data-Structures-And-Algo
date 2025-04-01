#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print (vector<int> & v) {
        for(int i=0; i<v.size(); i++) {
            cout << v[i] << " ";
        }
}
void bubbleSort(vector<int> & v) {
        int n = v.size();
        for (int i=0; i<n-1; i++) {
            for (int j=0; j<n-i-1; j++) {
                if(v[j] > v[j+1]) {
                    swap (v[j], v[j+1]);
                }
            }
        }
}
void selectionSort(vector<int> &v) {
    int n = v.size();
    for(int i=0; i<n-1; i++) { // step 1 select minimum index  
        int minIndex = i; 
        for(int j=i+1; j<n; j++) {
            if (v[j] < v[minIndex]) {
                minIndex = j;
            }
        }
        swap (v[i], v[minIndex]);
    }
}
void insertionSort(vector<int> &v) {
    //i = 0; chodhna hai 
    for(int i=1; i<v.size(); i++) {
        int key = v[i];
        int j = i-1;
     // move element of arr [0,n-1] that are greater than
     // key to one postion ahead of their current position 
        while (j>=0 && v[j] > key) {
            v[j+1] = v[j];
            j--;
        }
            v[j+1] = key;
    }
}

void customComp(vector <int>& v) {
    sort (v.begin(), v.end());
}


int main () {

    vector<int> v = {45,33,55,22,11};
    // customComp(v);

    // for(int num : v) {
    //     cout << num << " ";
    // }

    //bubbleSort(v);
    selectionSort(v);
    //insertionSort(v);
    print(v);
}
