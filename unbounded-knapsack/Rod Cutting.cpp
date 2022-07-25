/*
Rod Cutting

Given a rod of length ‘n’, we are asked to cut the rod and sell the pieces in a
way that will maximize the profit. We are also given the price of every piece 
of length ‘i’ where ‘1 <= i <= n’.

Example:

Lengths: [1, 2, 3, 4, 5]
Prices: [2, 6, 7, 10, 13]
Rod Length: 5


*/

using namespace std;

#include <iostream>
#include <vector>


namespace {
	class RodCutting {

	public:
		int solveRodCutting(const vector<int>& lengths,
							vector<int>& prices,
							int n) {

			// base checks
			if (n <= 0 or
				prices.empty() or
				prices.size() != lengths.size()) {
				return 0;
			}

			int lengthCount = lengths.size();
			vector<vector<int>> dp(lengthCount, vector<int>(n+1, 0));

			// process all rod lengths for all prices
			for (int i = 0; i < lengthCount; i++) {
				for (int len = 1; len <= n; len++) {
					int profit1 = 0, profit2 = 0;

					if (lengths[i] <= len) {
						profit1 = dp[i][len - lengths[i]] + prices[i];
					}

					if (i > 0) {
						profit2 = dp[i - 1][len];
					}

					dp[i][len] = max(profit1, profit2);
				}
			}

			// maximum price will be at the bottom-right corner.
			return dp[lengthCount - 1][n];
		}
	};

} // namespace
