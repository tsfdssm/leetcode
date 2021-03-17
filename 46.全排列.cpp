/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
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
                if (flag[j])
                {
                    tmp.push_back(nums[j]);
                    flag[j] = false;
                    dfs(nums);
                    flag[j] = true;
                    tmp.pop_back();
                }
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        if (0 == nums.size())
            return res;
        n = nums.size();
        flag.resize(n, true);
        dfs(nums);
        return res;
    }
};
// @lc code=end
