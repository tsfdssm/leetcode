/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        int res = 0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; ++i)
            for (int j = 1; j <= n; ++j)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    res = max(res, dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        // for (int i = m - 1; i >= 0; --i)
        //     for (int j = n - 1; j >= 0; --j)
        //     {
        //         if (nums1[i] == nums2[j])
        //         {
        //             dp[i][j] = dp[i + 1][j + 1] + 1;
        //             res = max(res, dp[i][j]);
        //         }
        //         else
        //             dp[i][j] = 0;
        //     }
        return res;
    }
};
// @lc code=end
