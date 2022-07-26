/*
Maximum Sum Increasing Subsequence

Given a number sequence, find the increasing subsequence with the highest sum.
Write a method that returns the highest sum.

Example 1:

Input: {4,1,2,6,10,1,12}
Output: 32
Explanation: The increaseing sequence is {4,6,10,12}.
Please note the difference, as the LIS is {1,2,6,10,12} which has a sum of '31'.
Example 2:

Input: {-4,10,3,7,15}
Output: 25
Explanation: The increaseing sequences are {10, 15} and {3,7,15}.


if num[i] > num[j] => dp[i] = dp[j] + num[i] if there is no bigger MSIS for 'i'


*/

using namespace std;

#include <iostream>
#include <vector>

namespace {
	class MSIS {

	public:
		int findMSIS(const vector<int>& nums) {
			int n = nums.size();
			vector<int> dp(n, 0);
			dp[0] = nums[0];

			int maxSum = nums[0];
			for (int i = 1; i < n; ++i) {

				// Every number is a LIS of length '1'
				dp[i] = nums[i];

				for (int j = 0; j < i; ++j) {
					if (nums[i] > nums[j] && dp[i] < dp[j] + nums[i]) {
						dp[i] = dp[j] + nums[i];
					}

					maxSum = max(maxSum, dp[i]);
				}
			}

			return maxSum;
		}
	};
} // namespace