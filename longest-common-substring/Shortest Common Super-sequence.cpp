/*
Shortest Common Super-sequence

Given two sequences ‘s1’ and ‘s2’, write a method to find the length of the 
shortest sequence which has ‘s1’ and ‘s2’ as subsequences.

Example 1:
Input: s1: "abcf" s2:"bdcf"
Output: 5
Explanation: The shortest common super-sequence (SCS) is "abdcf".

Example 2:
Input: s1: "dynamic" s2:"programming"
Output: 15
Explanation: The SCS is "dynprogrammicng".


if s1[i] == s2[j]
  dp[i][j] = 1 + dp[i-1][j-1]
else
  dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1])

*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>


namespace {
	class SCS {

	public:
		int findSCSLength(const string& s1, const string& s2) {
			int n1 = s1.length(),
				n2 = s2.length();


			vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));

			// if one of the strings is of zero length,
			// SCS would be equal to the length of the other string
			for (int i = 0; i <= n1; ++i) {
				dp[i][0] = i;
			}

			for (int i = 0; i <= n2; ++i) {
				dp[0][i] = i;
			}


			for (int i = 1; i <= n1; ++i) {
				for (int j = 1; j <= n2; ++j) {
					if (s1[i - 1] == s2[i - 2]) {
						dp[i][j] = 1 + dp[i - 1][j - 1];
					}
					else {
						dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
					}
				}
			}

			return dp[n1][n2];
		}
	};

} // namespace