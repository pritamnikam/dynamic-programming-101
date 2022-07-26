/*
Edit Distance

Given strings s1 and s2, we need to transform s1 into s2 by deleting, inserting, or replacing characters. 
Write a function to calculate the count of the minimum number of edit operations.

Example 1:

Input: s1 = "bat"
       s2 = "but"
Output: 1
Explanation: We just need to replace 'a' with 'u' to transform s1 to s2.
Example 2:

Input: s1 = "abdca"
       s2 = "cbda"
Output: 2
Explanation: We can replace first 'a' with 'c' and delete second 'c'.
Example 3:

Input: s1 = "passpot"
       s2 = "ppsspqrt"
Output: 3
Explanation: Replace 'a' with 'p', 'o' with 'q', and insert 'r'.

Basic Solution#
A basic brute-force solution could be to try all operations (one by one) on each character of s1. 
We can iterate through s1 and s2 together. Let’s assume index1 and index2 point to the current 
indexes of s1 and s2 respectively, so we have two options at every step:

1. If the strings have a matching character, we can recursively match for the remaining lengths.
2. If the strings don’t match, we start three new recursive calls representing the three edit operations. 
Whichever recursive call returns the minimum count of operations will be our answer.

*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>

namespace {
    class EditDistance {

    public:
        int findMinOperations(const string& s1, const string& s2) {
            int n1 = s1.length(),
                n2 = s2.length();

            vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));

            // if s2 is empty, we can remove all the characters of s1 to make it empty too
            for (int i = 0; i <= n1; ++i) {
                dp[i][0] = i;
            }

            // if s1 is empty, we have to insert all the characters of s2
            for (int i = 0; i <= n2; ++i) {
                dp[0][i] = i;
            }

            for (int i = 1; i <= n1; ++i) {
                for (int j = 1; j <= n2; ++j) {
                    // If the strings have a matching character, we can recursively
                    // match for the remaining lengths
                    if (s1[i - 1] == s2[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    else {
                        dp[i][j] = 1 + min(
                            dp[i - 1][j - 1],
                            min(dp[i - 1][j], dp[i][j - 1])
                        );
                    }
                }
            }

            return dp[n1][n2];
        }
    };

}