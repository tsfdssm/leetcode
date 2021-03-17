/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        int n = 1;
        int cur = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            // if (cur == nums[i])
            //     continue;
            if (cur != nums[i])
            {
                n++;
                cur = nums[i];
                nums[n - 1] = cur;
            }
        }
        return n;
    }
};
// @lc code=end
