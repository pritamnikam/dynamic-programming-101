/*
Longest Increasing Subsequence

Given a number sequence, find the length of its Longest Increasing Subsequence (LIS). 
In an increasing subsequence, all the elements are in increasing order (from lowest to highest).

Example 1:

Input: {4,2,3,6,10,1,12}
Output: 5
Explanation: The LIS is {2,3,6,10,12}.
Example 1:

Input: {-4,10,3,7,15}
Output: 4
Explanation: The LIS is {-4,3,7,15}.


if num[i] > num[j] => dp[i] = dp[j] + 1 if there is no bigger LIS for 'i'


*/

namespace {
	using namespace std;

#include <iostream>
#include <vector>

	class LIS {

	public:
		int findLISLength(const vector<int>& nums) {
			int n = nums.size();

			vector<int> dp(n, 1);
			dp[0] = 1;

			int maxLength = 1;

			for (int i = 1; i < n; ++i) {

				dp[i] = 1;

				for (int j = 0; j < i; ++j) {
					if (nums[i] > nums[j] and dp[i] <= dp[j]) {
						dp[i] = 1 + dp[j];
						maxLength = max(maxLength, dp[i]);
					}
				}
			}

			return maxLength;
		}
	};
}