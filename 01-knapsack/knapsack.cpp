/*
0/1 Knapsack

Given two integer arrays to represent weights and profits of ‘N’ items, 
we need to find a subset of these items which will give us maximum profit
such that their cumulative weight is not more than a given number ‘C’.

Write a function that returns the maximum profit. Each item can only be 
selected once, which means either we put an item in the knapsack or skip it.


for each item 'i'
  create a new set which INCLUDES item 'i' if the total weight does not exceed the capacity, and
	 recursively process the remaining capacity and items
  create a new set WITHOUT item 'i', and recursively process the remaining items
return the set from the above two sets with higher profit

Solution:
dp[i][c] = max (dp[i-1][c], 
				profits[i] + dp[i-1][c-weights[i]])

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
			// boundary checks
			if (profits.empty() &&
				profits.size() != weights.size() &&
				capacity == 0) {
				return 0;
			}

			int n = profits.size();
			vector<vector<int>> dp(n,
								   vector<int>(1 + capacity));

			// populate the capacity=0 columns, with '0' capacity we have '0' profit
			for (int i = 0; i < n; i++) {
				dp[i][0] = 0;
			}

			// if we have only one weight, we will take it if it is not more than the capacity
			for (int c = 0; c <= capacity; c++) {
				if (weights[0] <= c) {
					dp[0][c] = profits[0];
				}
			}

			for (int i = 1; i < n; ++i) {
				for (int c = 0; c <= capacity; c++) {
					int p1 = 0, p2 = 0;

					// profit w/o picking the item
					p1 = dp[i - 1][c];

					if (weights[i] <= c) {
						// profit w/ picking the item
						p2 = profits[i] + 
							 dp[i - 1][c - weights[i]];
					}

					dp[i][c] = max(p1, p2);
				}
			}

			printSelectedElements(dp, weights, profits, capacity);
			return dp[n - 1][capacity];
		}


		void printSelectedElements(vector<vector<int>>& dp,
			const vector<int>& profits,
			const vector<int>& weights,
			int capacity) {

			cout << "Selected weights:";
			int n = weights.size();
			int totalProfit = dp[n - 1][capacity];

			// for all items avaialble
			for (int i = n - 1; i > 0; i--) {
				if (totalProfit != dp[i-1][capacity]) {
					cout << " " << weights[i];
					capacity -= weights[i];
					totalProfit -= profits[i];
				}
			}

			if (totalProfit != 0) {
				cout << " " << weights[0];
			}
			cout << "" << endl;
		}
	};
} // namespace
