/*
Longest Alternating Subsequence

Given a number sequence, find the length of its Longest Alternating Subsequence (LAS). 
A subsequence is considered alternating if its elements are in alternating order.

A three element sequence (a1, a2, a3) will be an alternating sequence if its elements
hold one of the following conditions:

{a1 > a2 < a3 } or { a1 < a2 > a3}.

Example 1:

Input: {1,2,3,4}
Output: 2
Explanation: There are many LAS: {1,2}, {3,4}, {1,3}, {1,4}
Example 2:

Input: {3,2,1,4}
Output: 3
Explanation: The LAS are {3,2,4} and {2,1,4}.
Example 3:

Input: {1,3,2,4}
Output: 4
Explanation: The LAS is {1,3,2,4}.


Basic Solution#
A basic brute-force solution could be to try finding the LAS starting from every number 
in both ascending and descending order. So for every index ‘i’ in the given array, 
we will have three options:

1. If the element at ‘i’ is bigger than the last element we considered, we include the element at ‘i’ 
and recursively process the remaining array to find the next element in descending order.
2. If the element at ‘i’ is smaller than the last element we considered, we include the element at ‘i’ 
and recursively process the remaining array to find the next element in ascending order.
3. In addition to the above two cases, we can always skip the element ‘i’ to recurse for the remaining array.
This will ensure that we try all subsequences.

LAS would be the maximum of the above three subsequences.


if num[i] > num[j] => dp[i][0] = 1 + dp[j][1], if there is no bigger LAS for 'i'

if num[i] < num[j] => dp[i][1] = 1 + dp[j][0], if there is no bigger LAS for 'i'

*/

using namespace std;

#include <iostream>
#include <vector>


namespace {
    class LAS {

    public:
        int findLASLength(const vector<int>& nums) {
            if (nums.empty()) {
                return 0;
            }

            // dp[i][0] = stores the LAS ending at 'i' such that the last two elements are in ascending
            // order dp[i][1] = stores the LAS ending at 'i' such that the last two elements are in
            // descending order

            vector<vector<int>> dp(nums.size(), vector<int>(2));

            int maxLength = 1;
            for (int i = 0; i < nums.size(); i++) {
                // every single element can be considered as LAS of length 1
                dp[i][0] = dp[i][1] = 1;

                for (int j = 0; j < i; j++) {
                    if (nums[i] > nums[j]) {
                        // if nums[i] is BIGGER than nums[j] then we will consider the LAS ending at 'j'
                        // where the last two elements were in DESCENDING order
                        dp[i][0] = max(dp[i][0], 1 + dp[j][1]);
                        maxLength = max(maxLength, dp[i][0]);
                    }

                    else if (nums[i] != nums[j]) { // if the numbers are equal don't do anything
                   // if nums[i] is SMALLER than nums[j] then we will consider the LAS ending at
                   // 'j' where the last two elements were in ASCENDING order
                        dp[i][1] = max(dp[i][1], 1 + dp[j][0]);
                        maxLength = max(maxLength, dp[i][1]);
                    }
                }
            }
            return maxLength;
        }
    };

} // namespace