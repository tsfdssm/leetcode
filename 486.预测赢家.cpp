/*
 * @lc app=leetcode.cn id=486 lang=cpp
 *
 * [486] 预测赢家
 */

// @lc code=start
class Solution
{
public:
    bool PredictTheWinner(vector<int> &nums)
    {
        return win(nums, 0, nums.size(), 0) != -1;
    }

    int win(vector<int> &nums, int l, int r, long long gap)
    {
        if (r == l + 1)
        {
            if (nums[l] + gap > 0)
                return 1;
            else if (nums[l] + gap < 0)
                return -1;
            else
                return 0;
        }

        int r1 = win(nums, l + 1, r, -gap - nums[l]);
        int r2 = win(nums, l, r - 1, -gap - nums[r - 1]);
        if ((r1 == 1) && (r2 == 1))
            return -1;
        if ((r1 == 0) || (r2 == 0))
            return 0;
        return 1;
    }
};
// @lc code=end
