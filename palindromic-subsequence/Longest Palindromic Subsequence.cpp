/*
Longest Palindromic Substring

Given a string, find the length of its Longest Palindromic Substring (LPS). 
In a palindromic string, elements read the same backward and forward.

Example 1:

Input: "abdbca"
Output: 3
Explanation: LPS is "bdb".
Example 2:

Input: = "cddpd"
Output: 3
Explanation: LPS is "dpd".
Example 3:

Input: = "pqr"
Output: 1
Explanation: LPS could be "p", "q" or "r".


if st[startIndex] == st[endIndex], and
		if the remaing string is of zero length or dp[startIndex+1][endIndex-1] is a palindrome then
   dp[startIndex][endIndex] = true
*/


using namespace std;

#include <iostream>
#include <string>
#include <vector>


namespace {

	class LPS {

	public:
		int findLPSLength(const string& st) {
			int n = st.length();
			// dp[i][j] will be 'true' if the string from index 'i' to index 'j' is a palindrome
			vector<vector<bool>> dp(n, vector<bool>(n));

			// every string with one character is a palindrome
			for (int i = 0; i < n; i++) {
				dp[i][i] = true;
			}

			int maxLength = 0;
			for (int i = n - 1; i >= 0; --i) {
				for (int j = i + 1; j < n; ++j) {
					if (st[i] == st[j]) {
						// if it's a two character string or
						// if the remaining string is a palindrome too
						if ((j - i == 1) or
							dp[i + 1][j - 1]) {
							dp[i][j] = true;
							maxLength = max(maxLength, j - i + 1);
						}
					}
				}
			}

			return maxLength;
		}
	};

}
