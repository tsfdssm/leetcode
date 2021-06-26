/*
 * @lc app=leetcode.cn id=526 lang=cpp
 *
 * [526] 优美的排列
 */

// @lc code=start
class Solution
{
public:
    int res = 0;

    void dfs(int n, int pos, vector<int> &vis)
    {
        if (pos > n)
        {
            ++res;
            return;
        }
        for (int i = 1; i <= n; ++i)
        {
            if ((0 == vis[i]) && (pos % i == 0 || i % pos == 0))
            {
                vis[i] = 1;
                dfs(n, pos + 1, vis);
                vis[i] = 0;
            }
        }
    }
    int countArrangement(int n)
    {
        vector<int> vis(n + 1, 0);
        dfs(n, 1, vis);
        return res;
    }
};
// @lc code=end
