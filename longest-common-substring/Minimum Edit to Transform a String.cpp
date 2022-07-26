/*
Minimum Deletions & Insertions to Transform a String into another

Given strings s1 and s2, we need to transform s1 into s2 by deleting and inserting characters.
Write a function to calculate the count of the minimum number of deletion and insertion operations.

Example 1:

Input: s1 = "abc"
       s2 = "fbc"
Output: 1 deletion and 1 insertion.
Explanation: We need to delete {'a'} and insert {'f'} to s1 to transform it into s2.
Example 2:

Input: s1 = "abdca"
       s2 = "cbda"
Output: 2 deletions and 1 insertion.
Explanation: We need to delete {'a', 'c'} and insert {'c'} to s1 to transform it into s2.
Example 3:

Input: s1 = "passport"
       s2 = "ppsspt"
Output: 3 deletions and 1 insertion
Explanation: We need to delete {'a', 'o', 'r'} and insert {'p'} to s1 to transform it into s2.

*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>


namespace {
    class MDI {

    public:
        void findMDI(const string& s1, const string& s2) {
            int c1 = longestCommonSubsequence(s1, s2);
            cout << "Minimum deletions needed: " << (s1.length() - c1) << endl;
            cout << "Minimum insertions needed: " << (s2.length() - c1) << endl;
        }

    private:
        int longestCommonSubsequence(const string& s1, const string& s2) {
            int n1 = s1.length(),
                n2 = s2.length();

            vector<vector<int>> dp(
                n1 + 1,
                vector<int>(
                    n2 + 1,
                    0
                    )
            ); 

            int maxLength = 0;
            for (int i = 1; i <= n1; i++) {
                for (int j = 1; j <= n2; ++j) {
                    if (s1[i - 1] == s2[j - 1]) {
                        dp[i][j] = 1 + dp[i - 1][j - 1];
                    }
                    else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }

                    maxLength = max(maxLength, dp[i][j]);
                }
            }

            return maxLength;
        }
    };

}