#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //tabulation method
    int solveUsingTabulation(int n) {
        //step1: create dp array
        vector<int> dp(n+1, -1);

        // Step 2: Analyze base case and fill dp array
        if (n == 0) return 0;
        if (n == 1) return 1;

        dp[0] = 0;
        dp[1] = 1;

        //step3: fill the remaining dp array
        //array size = n+1
        //index move from 0 to n
        //0 and 1 index ko already fill krdia hai
        //2 index se n index tak abhi filled nahi h
        for(int index = 2; index <= n; index++) {
            //copy paste kro recursive logic ko
            //replace recursive calls with dp array
            //make sure dp array is using looping array
            dp[index] = dp[index-1] + dp[index-2];
        }
        return dp[n];
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = sol.solveUsingTabulation(n);
    cout << "Fibonacci of " << n << " is: " << result << endl;

    return 0;
}