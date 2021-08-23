/*
 * @lc app=leetcode.cn id=944 lang=cpp
 *
 * [944] 删列造序
 */

// @lc code=start
class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int res = 0;
        int n = strs[0].size();
        int m = strs.size();
        for (int i = 0; i < n; ++i)
        {
            bool flag = true;
            for (int j = 1; j < m; ++j)
            {
                if (strs[j - 1][i] > strs[j][i])
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                ++res;
        }
        return res;
    }
};
// @lc code=end
