/*
Minimum Coin Change

Given an infinite supply of ‘n’ coin denominations and a total money amount, 
we are asked to find the minimum number of coins needed to make up that amount.

dp[index][t] = min(dp[index-1][t],
				   dp[index][t-denominations[index]] + 1)

*/

using namespace std;

#include <iostream>
#include <limits>
#include <vector>


namespace {
	class CoinChange {

	public:
		int countChange(const vector<int>& denominations, int total) {
			if (denominations.empty())
				return numeric_limits<int>::max();

			int n = denominations.size();
			vector<vector<int>> dp(n, vector<int>(1 + total, 
												  numeric_limits<int>::max()));

			for (int i = 0; i < n; ++i) dp[i][0] = 0;

			for (int i = 0; i < n; ++i) {
				for (int t = 0; t <= total; ++t) {
					// exclude the coin
					if (i > 0)
						dp[i][t] = dp[i - 1][t];

					// include the coin
					if (t >= denominations[i]) {
						if (dp[i][t - denominations[i]] != numeric_limits<int>::max()) {
							dp[i][t] = min(dp[i][t], 1 + dp[i][t - denominations[i]]);
						}
					}
				}
			}

			// total combinations will be at the bottom-right corner.
			return (dp[n - 1][total] == numeric_limits<int>::max() ? -1 : dp[n - 1][total]);
		}
	};

} // namespace