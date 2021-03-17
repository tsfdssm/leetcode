/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution
{
public:
    int　N, K;
    vector<int> tmp;
    vector<vector<int>> res;
    void dfs(int n)
    {
        if (tmp.size() + (N - n + 1) < K)
        {
            return;
        }
        if (tmp.size() == K)
        {
            res.emplace_back(tmp);
            return;
        }
        else
        {
            tmp.push_back(n);
            dfs(n + 1);
            tmp.pop_back();
            dfs(n + 1);
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        K = k;
        N = n;
        dfs(1);
        return res;
    }
};
// @lc code=end
