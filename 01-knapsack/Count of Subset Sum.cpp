/*
Count of Subset Sum

Given a set of positive numbers, find the total number of subsets 
whose sum is equal to a given number ‘S’.

*/

using namespace std;

#include <iostream>
#include <vector>


namespace {
	class SubsetSum {
	public:
		int countSubsets(const vector<int>& num, int sum) {
			int n = num.size();
			vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

			for (int i = 0; i < n; ++i) dp[i][0] = 0;
			for (int i = 0; i <= sum; ++i) dp[0][i] = (i == num[0]) ? 1 : 0;

			for (int i = 1; i < n; ++i) {
				for (int j = 0; j <= sum; ++j) {
					dp[i][j] = dp[i - 1][j]; // exclude the number
					if (num[i] <= j) {
						dp[i][j] += dp[i - 1][j - num[i]]; // include the number, if it does not exceed the sum
					}
				}
			}

			return dp[n - 1][sum];
		}
	};
} // namespace