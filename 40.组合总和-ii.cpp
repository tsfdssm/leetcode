/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution
{

public:
    vector<vector<int>> res;
    vector<int> tmp;
    vector<bool> flag;
    int tar = 0, sum = 0;
    void dfs(int n, vector<int> &candidates)
    {
        if (sum > tar)
        {
            return;
        }
        else if (sum == tar)
        {
            res.emplace_back(tmp);
            return;
        }
        else
        {
            for (int i = n; i < candidates.size(); ++i)
            {
                if (i > n && candidates[i] == candidates[i - 1])
                    continue;
                tmp.push_back(candidates[i]);
                sum += candidates[i];
                dfs(i + 1, candidates);
                tmp.pop_back();
                sum -= candidates[i];
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        tar = target;
        dfs(0, candidates);
        return res;
    }
};
// @lc code=end
