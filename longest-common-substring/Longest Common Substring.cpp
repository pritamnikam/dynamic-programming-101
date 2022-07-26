/*
Longest Common Substring

Given two strings ‘s1’ and ‘s2’, find the length of the longest substring which is 
common in both the strings.

Example 1:

Input: s1 = "abdca"
       s2 = "cbda"
Output: 2
Explanation: The longest common substring is "bd".
Example 2:

Input: s1 = "passport"
       s2 = "ppsspt"
Output: 3
Explanation: The longest common substring is "ssp".

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

            vector<vector<int>> dp(n1 + 1, 
                                   vector<int>(n2 + 1, 0));

            int result = 0;
            for (int i = 1; i <= n1; ++i) {
                for (int j = 1; j <= n2; ++j) {
                    if (s1[i-1] == s2[j-1]) {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                        result = max(result, dp[i][j]);
                    }
                }
            }

            return result;
        }
    };

} // namespace