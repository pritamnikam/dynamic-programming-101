/*
Minimum jumps to reach the end

Given an array of positive numbers, where each element represents the max number of jumps that can be made forward from that element, write a program to find the minimum number of jumps needed to reach the end of the array (starting from the first element). If an element is 0, then we cannot move through that element.

Example 1:

Input = {2,1,1,1,4}
Output = 3
Explanation: Starting from index '0', we can reach the last index through: 0->2->3->4
Example 2:

Input = {1,1,3,6,9,3,0,1,3}
Output = 4
Explanation: Starting from index '0', we can reach the last index through: 0->1->2->3->8


'jumps to reach current index' + 1
dp[end] = Math.min(dp[end], dp[start]+1);
*/


using namespace std;

#include <iostream>
#include <limits>
#include <vector>

namespace {
	class ArrayJump {
	public:
		int countMinJumps(const vector<int>& jumps) {
			// initialize with infinity, except the first index which should be zero as we start from there
			vector<int> dp(jumps.size(), numeric_limits<int>::max());
			dp[0] = 0;

			for (int start = 0; start < jumps.size() - 1; start++) {
				int farthest = min(start + jumps[start],
									(int)jumps.size());

				for (int end = 0; end <= farthest; ++end) {
					dp[end] = min(dp[end], 
								  1 + dp[start]);
				}
			}

			return dp[jumps.size() - 1];
		}
	};
} // namespace