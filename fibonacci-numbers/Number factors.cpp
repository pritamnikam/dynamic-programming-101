/*
Number factors

Given a number ‘n’, implement a method to count how many possible ways there
are to express ‘n’ as the sum of 1, 3, or 4.


for n >= 4:

CountWays(n) = CountWays(n-1) + 
               CountWays(n-3) + 
               CountWays(n-4);
               
*/

using namespace std;

#include <iostream>
#include <vector>

class ExpressNumber {

public:
	int CountWays(int n) {
        if (n <= 2) return 1;
        if (n == 3) return 2;

        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;
        dp[3] = 2;

        for (int i = 4; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 3] + dp[i - 4];
        }

        return dp[n];
	}
};