/*
 * @lc app=leetcode.cn id=810 lang=cpp
 *
 * [810] 黑板异或游戏
 */

// @lc code=start
class Solution
{
public:
    bool xorGame(vector<int> &nums)
    {
        int res = 0;
        for (int num : nums)
            res ^= num;
        return (res == 0) || (!(nums.size() & 1));
    }
};
// @lc code=end
