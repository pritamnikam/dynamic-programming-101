/*
Longest Bitonic Subsequence

Given a number sequence, find the length of its Longest Bitonic Subsequence (LBS). 
A subsequence is considered bitonic if it is monotonically increasing and then monotonically decreasing.

Example 1:

Input: {4,2,3,6,10,1,12}
Output: 5
Explanation: The LBS is {2,3,6,10,1}.
Example 2:

Input: {4,2,5,9,7,6,10,3,1}
Output: 7
Explanation: The LBS is {4,5,9,7,6,3,1}.


Solution:
A basic brute-force solution could be to try finding the Longest Decreasing Subsequences (LDS), 
starting from every number in both directions. So for every index ‘i’ in the given array, 
we will do two things:

1. Find LDS starting from ‘i’ to the end of the array.
2. Find LDS starting from ‘i’ to the beginning of the array.

LBS would be the maximum sum of the above two subsequences.

*/

using namespace std;

#include <iostream>
#include <vector>


namespace {
    class LBS {

    public:
        int findLBSLength(const vector<int>& nums) {
            int n = nums.size();

            vector<int> lds(n);
            vector<int> ldsReverse(n);

            // find LDS for every index up to the beginning of the array
            findLDS(nums, lds);

            // find LDS for every index up to the end of the array
            findLDSReverse(nums, ldsReverse);

            int maxLength = 0;
            for (int i = 0; i < nums.size(); i++) {
                maxLength = max(maxLength,
                                lds[i] + ldsReverse[i] - 1);
            }

            return maxLength;
        }


        void findLDS(const vector<int>& nums, vector<int>& lds) {
            for (int i = 0; i < nums.size(); i++) {
                lds[i] = 1; // every element is an LDS of length 1
                for (int j = i - 1; j >= 0; j--) {
                    if (nums[j] < nums[i]) {
                        lds[i] = max(lds[i], lds[j] + 1);
                    }
                }
            }
        }


        void findLDSReverse(const vector<int>& nums, vector<int>& ldsReverse) {
            for (int i = nums.size() - 1; i >= 0; i--) {
                ldsReverse[i] = 1; // every element is an LDS of length 1
                for (int j = i + 1; j < nums.size(); j++) {
                    if (nums[j] < nums[i]) {
                        ldsReverse[i] = max(ldsReverse[i], ldsReverse[j] + 1);
                    }
                }
            }
        }
    };

} // namespace