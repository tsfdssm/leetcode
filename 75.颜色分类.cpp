/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int i = 0, j = 0, k = 0;
        for (int num : nums)
            if (0 == num)
                ++i;
            else if (1 == num)
                ++j;
            else
                ++k;
        fill(nums.begin(), nums.begin() + i, 0);
        fill(nums.begin() + i, nums.begin() + i + j, 1);
        fill(nums.begin() + i + j, nums.end(), 2);
    }
};
// @lc code=end
