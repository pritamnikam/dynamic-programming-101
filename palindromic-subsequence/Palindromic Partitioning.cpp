/*
Palindromic Partitioning

Given a string, we want to cut it into pieces such that each piece is a palindrome. 
Write a function to return the minimum number of cuts needed.

Example 1:

Input: "abdbca"
Output: 3
Explanation: Palindrome pieces are "a", "bdb", "c", "a".
Example 2:

Input: = "cddpd"
Output: 2
Explanation: Palindrome pieces are "c", "d", "dpd".
Example 3:

Input: = "pqr"
Output: 2
Explanation: Palindrome pieces are "p", "q", "r".
Example 4:

Input: = "pp"
Output: 0
Explanation: We do not need to cut, as "pp" is a palindrome.

*/


using namespace std;

#include <iostream>
#include <string>
#include <vector>

namespace {
	class MPP {

	public:
		int findMPPCuts(const string& st) {
			// isPalindrome[i][j] will be 'true' if the string from index 'i' to index 'j' is a palindrome
			int n = st.length();
			vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

			// every string with one character is a palindrome
			for (int i = 0; i < n; i++) {
				isPalindrome[i][i] = true;
			}

			// populate isPalindrome table
			for (int i = n - 1; i >= 0; --i) {
				for (int j = i + 1; j < n; ++j) {
					if (st[i] == st[j]) {
						// if it's a two character string or if the remaining string is a palindrome too
						if (j - i == 1 or
							isPalindrome[i + 1][j - 1]) {
							isPalindrome[i][j] = true;
						}
					}
				}
			}


			// now lets populate the second table, every index in 'cuts' stores the minimum cuts needed
			// for the substring from that index till the end
			vector<int> cuts(n, 0);
			for (int startIndex = n - 1; startIndex >= 0; startIndex--) {
				int minCuts = n; // maximum cuts
				for (int endIndex = n - 1; endIndex >= startIndex; endIndex--) {
					if (isPalindrome[startIndex][endIndex]) {
						// we can cut here as we got a palindrome
						// also we dont need any cut if the whole substring is a palindrome
						minCuts = (endIndex == n - 1) ? 0 : min(minCuts, 1 + cuts[endIndex + 1]);
					}
				}
				cuts[startIndex] = minCuts;
			}

			return cuts[0];
		}
	};

} // namespace