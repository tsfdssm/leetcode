/*
 * @lc app=leetcode.cn id=386 lang=cpp
 *
 * [386] 字典序排数
 */

// @lc code=start
class Solution
{
public:
    vector<int> res;
    void dfs(int val, int target)
    {
        if (val > target)
            return;
        res.push_back(val);
        for (int i = 0; i <= 9; ++i)
            dfs(val * 10 + i, target);
    }
    vector<int> lexicalOrder(int n)
    {
        for (int i = 1; i <= 9; ++i)
            dfs(i, n);
        return res;
    }
};
// @lc code=end
