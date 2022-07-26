/*
Minimum Deletions to Make a Sequence Sorted

Given a number sequence, find the minimum number of elements that should be deleted 
to make the remaining sequence sorted.

Example 1:

Input: {4,2,3,6,10,1,12}
Output: 2
Explanation: We need to delete {4,1} to make the remaing sequence sorted {2,3,6,10,12}.
Example 2:

Input: {-4,10,3,7,15}
Output: 1
Explanation: We need to delete {10} to make the remaing sequence sorted {-4,3,7,15}.
Example 3:

Input: {3,2,1,0}
Output: 3
Explanation: Since the elements are in reverse order, we have to delete all except one to get a
sorted sequence. Sorted sequences are {3}, {2}, {1}, and {0}


Length-of-input-array - LIS()

*/

using namespace std;

#include <iostream>
#include <vector>


namespace {
	class MDSS {

	public:
		int findMinimumDeletions(const vector<int>& nums) {
			return nums.size() - findLongestIncresingSequence(nums);
		}

	private:
		int findLongestIncresingSequence(const vector<int>& nums) {
			int n = nums.size();

			vector<int> dp(n);
			dp[0] = 1;

			int maxLength = 1;
			for (int i = 1; i < n; ++i) {
				dp[i] = 1;
				for (int j = 0; j < i; ++j) {
					if (nums[i] > nums[j] && dp[i] <= dp[j]) {
						dp[i] = 1 + dp[j];
					}

					maxLength = max(maxLength, dp[i]);
				}
			}
			return maxLength;
		}
	};

} // namespace