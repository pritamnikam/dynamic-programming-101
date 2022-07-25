/*
Maximum Ribbon Cut

Given a number array to represent possible ribbon lengths and a total ribbon length ‘n,’ 
we need to find the maximum number of pieces that the ribbon can be cut into.


*/


using namespace std;

#include <iostream>
#include <limits>
#include <vector>


namespace {

	class CutRibbon {

	public:
		int countRibbonPieces(const vector<int>& ribbonLengths, int total) {
			int n = ribbonLengths.size();
			vector<vector<int>> dp(n,
				vector<int>(total + 1,
					numeric_limits<int>::min()));

			// populate the total=0 columns, as we don't need any ribbon to make zero total
			for (int i = 0; i < n; i++) {
				dp[i][0] = 0;
			}

			for (int i = 0; i < n; i++) {
				for (int t = 1; t <= total; t++) {
					// exclude the ribbon
					if (i > 0) {
						dp[i][t] = dp[i - 1][t];
					}

					// include the ribbon and check if the remaining length can be cut into available lengths
					if (t >= ribbonLengths[i] &&
						dp[i][t - ribbonLengths[i]] != numeric_limits<int>::min()) {
						dp[i][t] = max(dp[i][t], 
									   dp[i][t - ribbonLengths[i]] + 1);
					}
				}
			}

			// total combinations will be at the bottom-right corner, return '-1' if cutting is not possible
			return (dp[n - 1][total] == numeric_limits<int>::min() ? -1 : dp[n - 1][total]);
		}
	};
} // namespace