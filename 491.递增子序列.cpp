/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */

// @lc code=start
class Solution
{
public:
    vector<int> tmp;
    set<vector<int>> res;

    void dfs(vector<int> &nums, int i)
    {
        if (i == nums.size())
            return;

        dfs(nums, i + 1);
        if (!tmp.empty() && nums[i] < tmp.back())
            return;

        tmp.push_back(nums[i]);
        if (tmp.size() >= 2)
            res.emplace(tmp);
        dfs(nums, i + 1);
        tmp.pop_back();
    }
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        dfs(nums, 0);
        return vector<vector<int>>(res.begin(), res.end());
    }
};
// @lc code=end
