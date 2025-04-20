#include <iostream>
#include <vector>

using namespace std;

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

int solveUsingTabulation() {
    
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
    int capacity = 50;
    int index = 0;

    //creating 2d array because capacity and index both are changing
    vector<vector<int>> dp (capacity+1, vector<int>(wt.size()+1,-1));    //rows, column and initialize -1

    int ans = solveUsingMemo(capacity,wt,profit,index,dp);
    cout << "Max Profit: " << ans;
}