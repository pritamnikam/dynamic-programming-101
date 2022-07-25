/*
Target Sum

Given a set of positive numbers (non zero) and a target sum ‘S’. 
Each number should be assigned either a ‘+’ or ‘-’ sign. 

We need to find out total ways to assign symbols to make the sum
of numbers equal to target ‘S’.

1. Sum(s1) - Sum(s2) = S
2. Sum(s1) + Sum(s2) = Sum(num)

adding 1 and 2

=> Sum(s1) - Sum(s2) + Sum(s1) + Sum(s2) = S + Sum(num)
	=> 2 * Sum(s1) =  S + Sum(num)
	=> Sum(s1) = (S + Sum(num)) / 2
	
Find count of subsets of the given numbers whose sum is equal to:

=> (S + Sum(num)) / 2

*/


using namespace std;

#include <iostream>
#include <vector>


namespace {

class TargetSum {
public:
	int findTargetSubsets(const vector<int>& num, int s) {
		int totalSum = 0;
		for (int n : num) totalSum += n;

		// if 's + totalSum' is odd, we can't find a subset with sum equal to '(s + totalSum) / 2'
		if (totalSum < s || 
			(s + totalSum) % 2 == 1) {
			return 0;
		}

		return countSubsets(num, 
							(s + totalSum) / 2);
	}

	int countSubsets(const vector<int>& num, int sum) {
		int n = num.size();
		vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

		for (int i = 0; i < n; ++i) dp[i][0] = 0;
		for (int i = 0; i <= sum; ++i) dp[0][i] = (i == num[0]) ? 1 : 0;

		for (int i = 1; i < n; ++i) {
			for (int j = 0; j <= sum; ++j) {
				dp[i][j] = dp[i - 1][j]; // exclude the number
				if (num[i] <= j) {
					dp[i][j] += dp[i - 1][j - num[i]]; // include the number, if it does not exceed the sum
				}
			}
		}

		return dp[n - 1][sum];
	}
};

}  // namespace