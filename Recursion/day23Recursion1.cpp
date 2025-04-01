#include <iostream>
using namespace std;

int factorial(int n) {

    if(n == 1) {   // base case
        return 1;
    }
    if(n == 0) {
        return 1;
    }
    int recursionKaAns = factorial(n-1);   //recursion relation

    int finalAns = n * recursionKaAns;    //processing
    return finalAns;    
}

int power(int n) {
   
    if(n == 0) {  //base function
        return 1;
    }
    int ans = 2 * power(n-1);  //recursion calls
    return ans;
}

int fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    int ans = fibonacci(n-1) + fibonacci(n-2);
    return ans;
}

int sum (int n) {
    if (n == 1) {
        return 1;
    }
    int ans = n + sum(n-1);
    return ans;
}

int main () {
    //cout << factorial(5);    
    //cout << power(2);
    //cout << fibonacci(7);
    cout << sum(3);

}