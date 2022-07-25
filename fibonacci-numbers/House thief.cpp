/*
House thief

Given a number array representing the wealth of n houses, determine the maximum amount of 
money the thief can steal without alerting the security system.

Example 1:

Input: {2, 5, 1, 3, 6, 2, 4}
Output: 15
Explanation: The thief should steal from houses 5 + 6 + 4
Example 2:

Input: {2, 10, 14, 8, 1}
Output: 18
Explanation: The thief should steal from houses 10 + 8

*/

using namespace std;

#include <iostream>
#include <vector>

namespace {

    class HouseThief {
    public:

        int findMaxSteal(const vector<int>& wealth) {
            int include = 0,
                exclude = 0;

            for (auto num : wealth) {
                int newInclude = exclude + num;
                exclude = max(exclude, include);
                include = newInclude;
            }

            return max(include, exclude);
        }
    };
}