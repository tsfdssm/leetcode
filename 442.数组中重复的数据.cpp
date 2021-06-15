/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 */

// @lc code=start
class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == i + 1)
                continue;
            if (nums[nums[i] - 1] == nums[i])
                continue;
            else
            {
                swap(nums[i], nums[nums[i] - 1]);
                --i;
            }
        }
        for (int i = 0; i < n; ++i)
            if (nums[i] != i + 1)
                res.push_back(nums[i]);
        return res;
    }
};
// @lc code=end
