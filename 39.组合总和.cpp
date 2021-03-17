/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{

public:
    vector<vector<int>> res;
    vector<int> tmp;
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
                tmp.push_back(candidates[i]);
                sum += candidates[i];
                dfs(i, candidates);
                tmp.pop_back();
                sum -= candidates[i];
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        tar = target;
        dfs(0, candidates);
        return res;
    }
};
// @lc code=end
