/*
Staircase

Given a stair with ‘n’ steps, implement a method to count how many possible ways
are there to reach the top of the staircase, given that, at every step you can 
either take 1 step, 2 steps, or 3 steps.

Example 1:

Number of stairs (n) : 3
Number of ways = 4
Explanation: Following are the four ways we can climb : {1,1,1}, {1,2}, {2,1}, {3}
Example 2:

Number of stairs (n) : 4
Number of ways = 7
Explanation: Following are the seven ways we can climb : {1,1,1,1}, {1,1,2}, {1,2,1}, {2,1,1},
{2,2}, {1,3}, {3,1}



// Fibonacci number pattern
CountWays(n) = CountWays(n-1) + CountWays(n-2) + CountWays(n-3), for n >=3

CountWays(n) = CountWays(n-1) + CountWays(n-2) + CountWays(n-3) + ... + CountWays(n-k), for n >= k

*/

using namespace std;

#include <iostream>
#include <vector>

namespace {
	class Staircase {

	public:
		int CountWays(int n) {
            if (n < 2) return 1;
            if (n == 2) return 2;

            int n1 = 1, n2 = 1, n3 = 2, temp;
            for (int i = 3; i <= n; i++) {
                temp = n1 + n2 + n3;
                n1 = n2;
                n2 = n3;
                n3 = temp;
            }
            return n3;
		}
	};

} // namespace