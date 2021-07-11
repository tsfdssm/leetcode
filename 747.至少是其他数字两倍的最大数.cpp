/*
 * @lc app=leetcode.cn id=747 lang=cpp
 *
 * [747] 至少是其他数字两倍的最大数
 */

// @lc code=start
class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        int n = nums.size();
        int idx = max_element(nums.begin(), nums.end()) - nums.begin();
        for (int i = 0; i < n; ++i)
        {
            if (idx == i)
                continue;
            if (nums[i] * 2 > nums[idx])
                return -1;
        }
        return idx;
    }
};
// @lc code=end
