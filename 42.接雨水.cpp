/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int l = 0, r = height.size() - 1;
        int l_max = 0, r_max = 0;
        int res = 0;
        while (l < r)
        {
            if (height[l] < height[r])
            {
                l_max < height[l] ? (l_max = height[l]) : (res += l_max - height[l]);
                l++;
            }
            else
            {
                r_max < height[r] ? (r_max = height[r]) : (res += r_max - height[r]);
                r--;
            }
        }
        return res;
    }
};
// @lc code=end
