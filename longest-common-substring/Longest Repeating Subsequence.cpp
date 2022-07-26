/*
Longest Repeating Subsequence

Given a sequence, find the length of its longest repeating subsequence (LRS).
A repeating subsequence will be the one that appears at least twice in the original 
sequence and is not overlapping (i.e. none of the corresponding characters in the 
repeating subsequences have the same index).

Example 1:

Input: “t o m o r r o w”
Output: 2
Explanation: The longest repeating subsequence is “or” {tomorrow}.

Example 2:

Input: “a a b d b c e c”
Output: 3
Explanation: The longest repeating subsequence is “a b c” {a a b d b c e c}.

Example 3:

Input: “f m f f”
Output: 2
Explanation: The longest repeating subsequence is “f f” {f m f f, f m f f}. Please note the second last character is shared in LRS.


*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>

namespace {
	class LRS {

	public:
		int findLRSLength(const string& str) {
			int n = str.length();

			vector<vector<int>> dp(n + 1, vector<int>(n + 1));
			int maxLength = 0;

			// dp[i1][i2] will be storing the LRS up to str[0..i1-1][0..i2-1]
			// this also means that subsequences of length zero (first row and column of dp[][]), will
			// always have LRS of size zero.

			for (int i = 1; i <= n; ++i) {
				for (int j = 1; j <= n; ++j) {
					if (i != j && str[i] == str[j]) {
						dp[i][j] = 1 + dp[i - 1][j - 1];
					}
					else {
						dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
					}

					maxLength = max(maxLength, dp[i][j]);
				}
			}

			return maxLength;
		}
	};
} // namesapce