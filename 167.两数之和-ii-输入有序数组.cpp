/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        //vector<int> res(2, 0);
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            if (target == nums[l] + nums[r])
                return vector{l + 1, r + 1};
            else if (target < nums[l] + nums[r])
                --r;
            else
            {
                ++l;
            }
        }
        return vector{0, 0};
    }
};
// @lc code=end
