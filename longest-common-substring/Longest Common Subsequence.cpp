/*
Longest Common Subsequence

Given two strings ‘s1’ and ‘s2’, find the length of the longest subsequence which
is common in both the strings.

A subsequence is a sequence that can be derived from another sequence by deleting
some or no elements without changing the order of the remaining elements.

Example 1:

Input: s1 = "abdca"
       s2 = "cbda"
Output: 3
Explanation: The longest common subsequence is "bda".
Example 2:

Input: s1 = "passport"
       s2 = "ppsspt"
Output: 5
Explanation: The longest common subsequence is "psspt".

*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>

namespace {
    class LCS {
    public:
        int findLCSLength(const string& s1, const string& s2) {
        
            int n1 = s1.length(),
                n2 = s2.length();

            vector<vector<int>> dp(
                n1 + 1,
                vector<int>(
                    n2 + 1,
                    0
                    )
            );

            int maxLength = 0;
            for (int i = 1; i <= n1; ++i) {
                for (int j = 1; j <= n2; ++j) {
                    if (s1[i-1] == s2[j-1]) {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    }
                    else {
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }

                    maxLength = max(
                        maxLength,
                        dp[i][j]
                    );
                }
            }

            return maxLength;
        }
    };
} // namespace