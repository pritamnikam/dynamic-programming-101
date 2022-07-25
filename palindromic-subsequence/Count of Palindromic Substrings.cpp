/*
Count of Palindromic Substrings

Given a string, find the total number of palindromic substrings in it. 
Please note we need to find the total number of substrings and not subsequences.

Example 1:

Input: "abdbca"
Output: 7
Explanation: Here are the palindromic substrings, "a", "b", "d", "b", "c", "a", "bdb".
Example 2:

Input: = "cddpd"
Output: 7
Explanation: Here are the palindromic substrings, "c", "d", "d", "p", "d", "dd", "dpd".
Example 3:

Input: = "pqr"
Output: 3
Explanation: Here are the palindromic substrings,"p", "q", "r".

*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>


namespace {
	class CPS {
	public:
		int findCPS(const string& st) {
			int n = st.length();
			vector<vector<bool>> dp(n, vector<bool>(n));

			int count = n;
			// every string with one character is a palindrome
			for (int i = 0; i < n; ++i)
				dp[i][i] = true;

			for (int i = n - 1; i >= 0; --i) {
				for (int j = i + 1; j < n; ++j) {
					if (st[i] == st[j]) {
						// if it's a two character string or 
						// if the remaining string is a palindrome too
						if (j - i == 1 or
							dp[i + 1][j - 1]) {
							dp[i][j] = true;
							++count;
						}
					}
				}
			}

			return count;
		}
	};
} // namespace