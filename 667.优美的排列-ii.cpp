/*
 * @lc app=leetcode.cn id=667 lang=cpp
 *
 * [667] 优美的排列 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> constructArray(int n, int k)
    {
        vector<int> res(n);
        for (int i = 0; i < n; ++i)
            res[i] = i + 1;
        int st = n - k;
        int ed = n;

        int idx = st - 1;
        int st_i = st - 1;
        while (st <= ed)
        {
            if ((idx - st_i) & 1)
            {
                res[idx] = ed;
                --ed;
            }
            else
            {
                res[idx] = st;
                ++st;
            }
            ++idx;
        }
        return res;
    }
};
// @lc code=end
