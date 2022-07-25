/*
Subset Sum

Given a set of positive numbers, determine if there exists a subset 
whose sum is equal to a given number ‘S’.

for each number 'i'
  create a new set which INCLUDES number 'i' if it does not exceed 'S', and recursively
	 process the remaining numbers
  create a new set WITHOUT number 'i', and recursively process the remaining numbers
return true if any of the above two sets has a sum equal to 'S', otherwise return false
*/

using namespace std;

#include <iostream>
#include <vector>

namespace {
	class SubsetSum {
	public:
		bool canPartition(const vector<int>& num, int sum) {
			int n = num.size();
			vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

			for (int i = 0; i < n; ++i) dp[0][i] = true; // zero - sum
			for (int i = 0; i <= sum; ++i) dp[i][0] = (i == num[0]); // only one number in array

			for (int i = 1; i < n; ++i) {
				for (int j = 0; j <= sum; ++j) {
					// if (dp[i - 1][j]) dp[i][j] = dp[i - 1][j]; // answer without selecting the number
					// else if (num[i] <= j) dp[i][j] = dp[i - 1][j - num[i]]; // number is smaller than sum required
					dp[i][j] = dp[i - 1][j] or  // answer without selecting the number
							   ((num[i] <= j) and dp[i - 1][j - num[i]]); // number is smaller than sum required
				}
			}

			return dp[n - 1][sum];
		}
	};
} // namespace