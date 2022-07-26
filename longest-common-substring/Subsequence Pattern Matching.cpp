/*
Subsequence Pattern Matching

Given a string and a pattern, write a method to count the number of times
the pattern appears in the string as a subsequence.

Example 1: Input: string: “baxmx”, pattern: “ax”
Output: 2
Explanation: {baxmx, baxmx}.

Example 2:

Input: string: “tomorrow”, pattern: “tor”
Output: 4
Explanation: Following are the four occurences: {tomorrow, tomorrow, tomorrow, tomorrow}.


if str[strIndex] == pat[patIndex] {
  dp[strIndex][patIndex] = dp[strIndex-1][patIndex-1]
}
dp[strIndex][patIndex] += dp[strIndex-1][patIndex]

*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>

namespace {
    class SPM {
    public:
        int findSPMCount(const string& str, const string& pat) {
            
            // every empty pattern has one match
            if (pat.length() == 0) {
                return 1;
            }

            if (str.length() == 0 || pat.length() > str.length()) {
                return 0;
            }

            // dp[strIndex][patIndex] will be storing the count of SPM up to
            // str[0..strIndex-1][0..patIndex-1]
            int n1 = str.length(),
                n2 = pat.length();

            vector<vector<int>> dp(n1 + 1, vector<int>(n2+1));

            // for the empty pattern, we have one matching
            for (int i = 0; i <= n1; i++) {
                dp[i][0] = 1;
            }


            for (int i = 1; i <= n1; ++i) {
                for (int j = 1; j <= n2; ++j) {
                    if (str[i-1] == pat[j-1]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    else {
                        dp[i][j] += dp[i - 1][j];
                    }
                }
            }

            return dp[n1][n2];
        }
    };
}