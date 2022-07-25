/*
Unbounded Knapsack

Given two integer arrays to represent weights and profits of ‘N’ items, we need to find a subset of 
these items which will give us maximum profit such that their cumulative weight is not more than a 
given number ‘C’. We can assume an infinite supply of item quantities; therefore, each item can be 
selected multiple times.

*/

/*
Unbounded Knapsack

Given two integer arrays to represent weights and profits of ‘N’ items, we need to find a subset of
these items which will give us maximum profit such that their cumulative weight is not more than a
given number ‘C’. We can assume an infinite supply of item quantities; therefore, each item can be
selected multiple times.

// dp[index][c] = max (dp[index-1][c],
					   profit[index] + dp[index][c-weight[index]]) 
*/

using namespace std;

#include <iostream>
#include <vector>


namespace {
	class Knapsack {

	public:

		int solveKnapsack(const vector<int>& profits,
						  const vector<int>& weights,
						  int capacity) {
			// boundary cases
			if (profits.empty() or 
				profits.size() != weights.size() or 
				capacity == 0) {
				return 0;
			}

			int n = profits.size();

			vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

			// populate the capacity=0 columns
			for (int i = 0; i < n; i++) {
				dp[i][0] = 0;
			}

			// process all sub-arrays for all capacities
			for (int i = 0; i < n; i++) {
				for (int c = 1; c <= capacity; c++) {
					int profit1 = 0, profit2 = 0;
					if (weights[i] <= c) {
						// unbounded supply of item 'i'
						profit1 = dp[i][c - weights[i]] + profits[i];
					}

					if (i > 0) {
						// dont choose item 'i'
						profit2 = dp[i - 1][c];
					}

					dp[i][c] = max(profit1, profit2);
				}
			}
			// maximum profit will be in the bottom-right corner.
			return dp[n - 1][capacity];
		}
	};

} // namespace
