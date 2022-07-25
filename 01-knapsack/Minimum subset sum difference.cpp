/*
Minimum Subset Sum Difference

Given a set of positive numbers, partition the set into two subsets with a 
minimum difference between their subset sums.


*/


using namespace std;

#include <iostream>
#include <vector>

namespace {

	class PartitionSet {
	public:
		int canPartition(const vector<int>& num) {
			int totalSum = 0;
			for (int n : num) totalSum += n;

			int n = num.size();
			int sum = totalSum / 2;

			vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

			for (int i = 0; i < n; ++i) dp[i][0] = true; // sum is zero
			for (int i = 0; i <= sum; ++i) dp[0][i] = (num[0] == i); // only one number in num array

			for (int i = 1; i < n; ++i) {
				for (int j = 0; j <= sum; ++j) {
					dp[i][j] = dp[i - 1][j] or
						((num[i] <= j) and dp[i - 1][j - num[i]]);
				}
			}

			// Find the largest index in the last row which is true
			int sum1 = 0;
			for (int i = sum; i >= 0; --i) {
				if (dp[n - 1][i]) {
					sum1 = i;
					break;
				}
			}

			// remaning sum:
			int sum2 = totalSum - sum1;
			return abs(sum1 - sum2);
		}
	};

} // namespace