/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> tmp;
    vector<vector<int>> res;
    void dfs(int n, vector<int> &nums)
    {

        res.emplace_back(tmp);
        for (int i = n; i < nums.size(); i++)
        {
            if (i > n && nums[i] == nums[i - 1])
                continue;
            tmp.push_back(nums[i]);
            dfs(i + 1, nums);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        dfs(0, nums);
        return res;
    }
};
// @lc code=end
