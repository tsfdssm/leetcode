/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */

// @lc code=start
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int l = 0, r = 0;
        int res = 0;
        int tmp = 0;
        for (; r < n; ++r)
        {
            if (0 == nums[r])
                ++tmp;
            while (tmp > k)
            {
                if (nums[l] == 0)
                    --tmp;
                ++l;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
// @lc code=end
