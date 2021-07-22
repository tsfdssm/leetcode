/*
 * @lc app=leetcode.cn id=775 lang=cpp
 *
 * [775] 全局倒置与局部倒置
 */

// @lc code=start
class Solution
{
public:
    bool isIdealPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int minn = INT_MAX;
        for (int i = n - 1; i >= 2; --i)
        {
            minn = min(minn, nums[i]);
            if (nums[i - 2] > minn)
                return false;
        }
        return true;
    }
};
// @lc code=end
