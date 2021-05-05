/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> tmp;
    int K = 0, N = 0;
    void dfs(int cur, int rest)
    {
        // if (rest < 0 || rest > (K - (int)tmp.size()) * 9 || (9 - cur + 1) < K - (int)tmp.size())
        //     return;
        if (rest < 0 || tmp.size() > K || cur > 9)
            return;

        //res.emplace_back(tmp);
        if (tmp.size() == (K - 1) && cur == rest)
        {

            res.emplace_back(tmp);
            res.back().push_back(cur);
            return;
        }
        tmp.push_back(cur);
        dfs(cur + 1, rest - cur);
        tmp.pop_back();
        dfs(cur + 1, rest);
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        K = k;
        N = n;
        dfs(1, n);
        return res;
    }
};
// @lc code=end
