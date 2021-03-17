/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (0 == nums.size() || 1 == nums.size())
            return true;
        int max = 0, n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (max < i)
                return false;
            max = max > (i + nums[i]) ? max : (i + nums[i]);
            if (max >= n - 1)
                return true;
        }
        return false;
    }
};
// @lc code=end
