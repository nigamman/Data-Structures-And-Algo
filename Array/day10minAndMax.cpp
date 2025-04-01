#include <iostream> 
#include <limits.h>
using namespace std;

int minInArray (int arr[], int size) {
    int minAns = INT_MAX;
    for(int i=0; i<size; i++) {
        minAns = min(arr[i], minAns);
    }
    //return minAns;
    cout << "Minimum " << minAns;
}

int maxInArray (int arr[], int size) {
    int maxAns = INT_MIN;
    for(int i=0; i<size; i++) {
        maxAns = max(arr[i], maxAns);
    }
    cout << "Maximum " << maxAns;
}

int main () {
    int arr[] = {3,5,7,2,8,-1,4,10,12};
    int size = 9;
    int minAns = minInArray(arr, size);

    cout << endl;

    int maxAns = maxInArray(arr, size);
    return 0;
}