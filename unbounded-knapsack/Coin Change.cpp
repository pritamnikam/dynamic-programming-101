/*
Coin Change

Given an infinite supply of �n� coin denominations and a total money amount,
we are asked to find the total number of distinct ways to make up that amount.

dp[index][t] = dp[index-1][t] + dp[index][t-denominations[index]]

*/

using namespace std;

#include <iostream>
#include <vector>

namespace {
	class CoinChange {
	public:
		int countChange(const vector<int>& denominations, int total) {
			int n = denominations.size();
			vector<vector<int>> dp(n, vector<int>(total + 1));

			// populate the total=0 columns, as we will always have an empty set for zero total
			for (int i = 0; i < n; i++) {
				dp[i][0] = 1;
			}

			// process all sub-arrays for all capacities
			for (int i = 0; i < n; i++) {
				for (int t = 1; t <= total; t++) {
					if (i > 0) {
						dp[i][t] = dp[i - 1][t];
					}

					if (t >= denominations[i]) {
						dp[i][t] += dp[i][t - denominations[i]];
					}
				}
			}

			// total combinations will be at the bottom-right corner.
			return dp[n - 1][total];
		}
	};
}