/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution
{
private:
    int n;
    vector<vector<int>> res;
    vector<int> tmp;
    vector<bool> flag;
    void dfs(vector<int> &nums)
    {
        if (tmp.size() == n)
            res.emplace_back(tmp);
        else
        {
            for (int j = 0; j < n; j++)
            {
                if (!flag[j] || (j > 0 && nums[j] == nums[j - 1] && flag[j - 1]))
                    continue;

                tmp.push_back(nums[j]);
                flag[j] = false;
                dfs(nums);
                flag[j] = true;
                tmp.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        if (0 == nums.size())
            return res;
        n = nums.size();
        sort(nums.begin(), nums.end());
        flag.resize(n, true);
        dfs(nums);
        return res;
    }
};
// @lc code=end
