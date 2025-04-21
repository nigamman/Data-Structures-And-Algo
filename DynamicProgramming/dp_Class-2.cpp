#include <iostream>
#include <vector>

using namespace std;

// 0/1 knapsack problem :

int solveUsingMemo(int capacity, vector<int> wt, vector<int> profit, int index, vector<vector<int>>& dp) {
    //base case
    if(index >= wt.size()) {
        return 0;
    }
    //check ans exists
    if(dp[capacity][index] != -1) {
        return dp[capacity][index];
    }
    int include = 0;
    if(wt[index] <= capacity) {
        include = profit[index] + solveUsingMemo(capacity-wt[index], wt, profit, index+1,dp);
    }
    
    int exclude = 0 + solveUsingMemo(capacity, wt, profit, index+1,dp);

    dp[capacity][index] = max(include,exclude);
    return dp[capacity][index];
}

int solveUsingTabulation(int capacityt, int n, int wtt[], int profitt[]) {
    
    //create dp array
    vector<vector<int>> dp(capacityt+1, vector<int>(n+1,-1));

    //maintain intital state of array
    for(int i=0; i<=capacityt; i++) {
        dp[i][n] = 0;
    }
    //fill remaining array
    for(int i=0; i<= capacityt; i++) {
        for(int j=n-1; j>=0; j--) {
            int include = 0;
            if(wtt[j] <= i) {
                include = profitt[j] + dp[i-wtt[j]][j+1];
            }
            int exclude = 0 + dp[i][j+1];

            dp[i][j] = max(include,exclude);
        }
    }
    return dp[capacityt][0];
}

int solveUsingRecursion(int capacity, vector<int> wt, vector<int> profit, int index) {
    //base case
    if(index >= wt.size()) {
        return 0;
    }
    int include = 0;
    if(wt[index] <= capacity) {
        include = profit[index] + solveUsingRecursion(capacity-wt[index], wt, profit, index+1);
    }
    
    int exclude = 0 + solveUsingRecursion(capacity, wt, profit, index+1);

    int ans = max(include,exclude);
    return ans;
}

int main () {
    vector<int> wt = {10,20,30};
    vector<int> profit = {60,100,120};
    int profitt[] = {60,100,120};
    int wtt[] = {10,20,30};
    int capacityt = 50;
    int capacity = 50;
    int index = 0;
    int n = 3;

    //creating 2d array because capacity and index both are changing
    vector<vector<int>> dp (capacity+1, vector<int>(wt.size()+1,-1));    //rows, column and initialize -1

    int ans = solveUsingMemo(capacity,wt,profit,index,dp);
    cout << "Max Profit using memoization: " << ans << endl;

    int ans2 = solveUsingTabulation(capacityt,n,wtt,profitt);
    cout << "Max Profit using tabulation: " << ans;
}