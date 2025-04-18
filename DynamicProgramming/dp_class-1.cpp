#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //Recursion + memoization
    int solveUsingMemo(int n, vector<int>&dp) {
        //base case
        if(n==0 || n==1) {
            return n;
        }
        //Step3: if ans already exist then return ans that is dp
        if(dp[n] != -1) {
            return dp[n];
        }
        //Step2: store and return using dp array
        dp[n] = solveUsingMemo(n-1, dp) + solveUsingMemo(n-2,dp);
        return dp[n];
    }
    int fib(int n) {
        //Step1: create dp array
        vector<int> dp(n+1,-1);
        return solveUsingMemo(n, dp);
    } 
};
int main () {
    Solution sol;
    int n;

    cout << "Enter a number: ";
    cin >> n;

    int result = sol.fib(n);
    cout << "Fibonacci of " << n << " is: " << result << endl;

    return 0;
}