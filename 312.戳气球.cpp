/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

// @lc code=start
class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> rec(n + 2, vector<int>(n + 2));
        vector<int> val(n + 2, 1);
        for (int i = 1; i <= n; ++i)
            val[i] = nums[i - 1];
        for (int i = 2; i <= n + 1; ++i)
            for (int j = i - 2; j >= 0; --j)
                for (int k = j + 1; k < i; ++k)
                {
                    int sum = val[i] * val[j] * val[k];
                    sum += rec[i][k] + rec[k][j];
                    rec[i][j] = max(rec[i][j], sum);
                }
        // for (int i = n - 1; i >= 0; --i)
        //     for (int j = i + 2; j <= n + 1; ++j)
        //         for (int k = i + 1; k < j; ++k)
        //         {
        //             int sum = val[i] * val[j] * val[k];
        //             sum += rec[i][k] + rec[k][j];
        //             rec[i][j] = max(rec[i][j], sum);
        //         }
        return rec[n + 1][0];
    }
};
// @lc code=end
