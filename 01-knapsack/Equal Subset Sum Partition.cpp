/*
Equal Subset Sum Partition

Given two integer arrays to represent weights and profits of ‘N’ items, 
we need to find a subset of these items which will give us maximum profit 
such that their cumulative weight is not more than a given number ‘C’. 

Write a function that returns the maximum profit. Each item can only be selected once, 
which means either we put an item in the knapsack or skip it.

Algo:

for each number 'i'
  create a new set which INCLUDES number 'i' if it does not exceed 'S/2', and recursively
      process the remaining numbers
  create a new set WITHOUT number 'i', and recursively process the remaining items
return true if any of the above sets has a sum equal to 'S/2', otherwise return false


dp[i][c] = max (dp[i-1][c], 
                profits[i] + dp[i-1][c-weights[i]])

*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

namespace {
    class PartitionSet {
    public:
        bool canPartition(const vector<int>& num) {
            int sum = 0;
            for (int n : num) sum += n;
            if (sum % 2) return false;

            int n = num.size();
            sum = sum / 2;
            vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

            for (int i = 0; i < n; ++i) dp[i][0] = true;
            for (int i = 0; i <= sum; ++i) dp[0][i] = (sum == num[i]);

            for (int i = 1; i < n; ++i) {
                for (int j = 0; j <= sum; ++j) {
                    if (dp[i - 1][j])
                        dp[i][j] = dp[i - 1][j];
                    else if (num[i] <= j)
                        dp[i][j] = dp[i - 1][j - num[j]];
                }
            }
            return dp[n - 1][sum];
        }
    };
}