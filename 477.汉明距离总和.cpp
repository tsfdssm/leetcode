/*
 * @lc app=leetcode.cn id=477 lang=cpp
 *
 * [477] 汉明距离总和
 */

// @lc code=start
class Solution
{
public:
    int totalHammingDistance(vector<int> &nums)
    {
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < 30; ++i)
        {
            int c = 0;
            for (int num : nums)
                c += (num >> i) & 1;
            res += c * (n - c);
        }
        return res;
    }
};
// @lc code=end
