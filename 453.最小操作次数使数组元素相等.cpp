/*
 * @lc app=leetcode.cn id=453 lang=cpp
 *
 * [453] 最小操作次数使数组元素相等
 */

// @lc code=start
class Solution
{
public:
    int minMoves(vector<int> &nums)
    {

        int sum = accumulate(nums.begin(), nums.end(), 0);
        int m = *min_element(nums.begin(), nums.end());
        int n = nums.size();

        return sum - (m * n);
    }
};
// @lc code=end
