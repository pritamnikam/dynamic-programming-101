/*
Minimum Deletions in a String to make it a Palindrome

Given a string, find the minimum number of characters that we can remove to make it a palindrome.

Example 1:

Input: "abdbca"
Output: 1
Explanation: By removing "c", we get a palindrome "abdba".
Example 2:

Input: = "cddpd"
Output: 2
Explanation: Deleting "cp", we get a palindrome "ddd".
Example 3:

Input: = "pqr"
Output: 2
Explanation: We have to remove any two characters to get a palindrome, e.g. if we
remove "pq", we get palindrome "r".


Minimum_deletions_to_make_palindrome = Length(st) - LPS(st)


*/


using namespace std;

#include <iostream>
#include <string>
#include <vector>

namespace {

	class MDSP {

	public:
		int findMinimumDeletions(const string& st) {
			return st.length() - findLPSLength(st);
		}

	private:
		int findLPSLength(const string& st) {
			int n = st.length();
			vector<vector<int>> dp(n, vector<int>(n));

			for (int i = 0; i < n; ++i)
				dp[i][i] = 1;


			for (int i = n - 1; i >= 0; --i) {
				for (int j = i + 1; j < n; ++j) {
					if (st[i] == st[j]) {
						dp[i][j] = 2 + dp[i + 1][j - 1];
					}

					else {
						dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
					}
				}
			}

			return dp[0][n - 1];
		}
	};
} // namespace