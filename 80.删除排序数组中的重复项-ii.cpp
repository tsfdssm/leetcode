/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        // int l = 0;
        // for (int r = 0; r < nums.size(); r++)
        // {
        //     if (l < 2 || nums[l - 2] < nums[r])
        //     {
        //         nums[l] = nums[r];
        //         l++;
        //     }
        // }
        // return l;
        int flag = 1;
        int len = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
            {
                if (1 == flag)
                    flag = 2;
                else
                {
                    nums.erase(nums.begin() + i--);
                    len--;
                }
            }
            else
            {
                flag = 1;
            }
        }
        return len;
    }
};
// @lc code=end
