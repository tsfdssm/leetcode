/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int i = 0;
        int n = nums.size();
        while (i < n)
        {
            if (nums[i] == val)
            {
                swap(nums[i], nums[n - 1]);
                n--;
            }
            else
            {
                i++;
            }
        }
        return n;
        // for (auto i = nums.begin(); i != nums.end();)
        // {
        //     if (*i == val)
        //         i = nums.erase(i);
        //     else
        //         i++;
        // }
        // return nums.size();
    }
};
// @lc code=end
