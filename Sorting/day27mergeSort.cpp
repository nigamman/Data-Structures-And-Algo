#include <iostream>
using namespace std;

void merge(int arr[], int s, int e) {

    int mid = (s+e)/2;
    
    int lenRight = e - mid;         //creating a length for right part of array.
    int lenLeft = mid - s + 1;  //creating a length for left part of array.

    int *left = new int[lenLeft];  // creating a left array
    int *right = new int[lenRight]; // creatin a right array

    int k = s; //k is a starting index of left array values
    for(int i=0; i<lenLeft; i++) {
        arr[k] = left[i];   //copy the value from original array to left array.
        k++;  
    }

        k = mid + 1; // k is a starting index of right array values
    for(int i=0; i<lenRight; i++) {
        arr[k] = right[i];      //copy the value from original array to right array.
        k++;
    }
    //actual merge is logic is here
    //left array is sorted
    //right array is sorted
    int lefIndex = 0;
    int rigIndex = 0;
    int mainArrayIndex = s; // yahin gaand fatti hai

    while(lefIndex < lenLeft && rigIndex < lenRight) {

        if(left[lefIndex] < arr[rigIndex]) {    //agar right badda hai to left se
            arr[mainArrayIndex] = left[lefIndex];  //copy kar denge main index mein left index ko
            lefIndex++;
            mainArrayIndex++;
        }
        else {
            arr[mainArrayIndex] = right[rigIndex]; // copy kar denge main index mein right index ko;            
            rigIndex++;
            mainArrayIndex++;
        }
    } 
                        //2 more cases
//1 case -> left array exhaust but right array me element abhi bhi bache hai
while(rigIndex < lenRight) {
	arr[mainArrayIndex] =  right[rigIndex];
	mainArrayIndex++;
	rigIndex++;
}
//2nd case -> rigght array exhaust but left array me element abhi bhi bache hai
while(lefIndex < lenLeft) {
	arr[mainArrayIndex] =  left[lefIndex];
	mainArrayIndex++;
	lefIndex++;
}
//1 more step pending
delete[] left;
delete[] right;
}

void mergeSort(int arr[], int s, int e) {
    //base case
    if(s>=e) {    //single element
        return;
    }
    //breaK
    int mid = (s+e)/2;  //break
    //left -> s to mid;
    //right -> mid+1 to e;

    mergeSort(arr,s,mid);        // recursive call for left array
    mergeSort(arr,mid+1,e);     // recursive call for right array
    merge(arr,s,e);            // merge two sorted array 
}

int main () {

    int arr[] = {2,1,6,9,4,5};
	int size = 6;
	int s = 0;
	int e = size - 1;

	cout << "Before merge sort: " << endl;
	for(int i=0; i<size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	mergeSort(arr,s,e);

	cout << "After merge sort: " << endl;
	for(int i=0; i<size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

    return 0;
}