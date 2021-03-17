/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution
{
public:
    vector<int> tmp;
    vector<vector<int>> res;
    void dfs(int n, vector<int> &nums)
    {
        if (n == nums.size())
        {
            res.emplace_back(tmp);
            return;
        }
        tmp.push_back(nums[n]);
        dfs(n + 1, nums);
        tmp.pop_back();
        dfs(n + 1, nums);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        dfs(0, nums);
        return res;
    }
};
// @lc code=end
