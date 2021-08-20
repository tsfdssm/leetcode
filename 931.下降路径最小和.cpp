/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
 */

// @lc code=start
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<int> dp = matrix[0];
        for (int i = 1; i < n; ++i)
        {
            vector<int> nxt = matrix[i];
            for (int i = 0; i < n; ++i)
            {
                int minn = INT_MAX;
                for (int k = -1; k <= 1; ++k)
                {
                    if (i + k < 0 || i + k >= n)
                        continue;
                    minn = min(minn, dp[i + k]);
                }
                nxt[i] += minn;
            }
            dp = move(nxt);
        }
        return *min_element(dp.begin(), dp.end());
    }
};
// @lc code=end
