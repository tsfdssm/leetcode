/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; ++i)
        {
            if ((nums[i] == i + 1) || nums[nums[i] - 1] == nums[i])
                continue;
            swap(nums[i], nums[nums[i] - 1]);
            --i;
        }
        for (int i = 0; i < n; ++i)
            if (nums[i] != i + 1)
                res.push_back(i + 1);
        return res;
    }
};
// @lc code=end
