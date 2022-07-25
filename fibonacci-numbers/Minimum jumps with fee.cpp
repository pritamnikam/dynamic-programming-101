/*
Minimum jumps with fee

Given a staircase with ‘n’ steps and an array of ‘n’ numbers representing the fee 
that you have to pay if you take the step. Implement a method to calculate the 
minimum fee required to reach the top of the staircase (beyond the top-most step). 

At every step, you have an option to take either 1 step, 2 steps, or 3 steps. 
You should assume that you are standing at the first step.

Example 1:
Number of stairs (n) : 6
Fee: {1,2,5,2,1,2}
Output: 3
Explanation: Starting from index '0', we can reach the top through: 0->3->top
The total fee we have to pay will be (1+2).

Example 2:
Number of stairs (n): 4
Fee: {2,3,4,5}
Output: 5
Explanation: Starting from index '0', we can reach the top through: 0->1->top
The total fee we have to pay will be (2+3).

*/

using namespace std;

#include <iostream>
#include <vector>

namespace {
	class Staircase {

	public:
		int findMinFee(const vector<int>& fee) {
            vector<int> dp(fee.size() + 1); // +1 to handle the 0th step
            dp[0] = 0;                      // if there are no steps, we dont have to pay any fee
            dp[1] = fee[0];                 // only one step, so we have to pay its fee
            // for 2 steps, since we start from the first step, so we have to pay its fee
            // and from the first step we can reach the top by taking two steps, so
            // we dont have to pay any other fee.
            dp[2] = fee[0];

            // please note that dp[] has one extra element to handle the 0th step
            for (int i = 2; i < fee.size(); i++) {
                dp[i + 1] = min(fee[i] + dp[i], 
                                min(fee[i - 1] + dp[i - 1], 
                                    fee[i - 2] + dp[i - 2]));
            }

            return dp[fee.size()];
		}
	};
}