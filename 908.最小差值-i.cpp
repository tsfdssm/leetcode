/*
 * @lc app=leetcode.cn id=908 lang=cpp
 *
 * [908] 最小差值 I
 */

// @lc code=start
class Solution
{
public:
    int smallestRangeI(vector<int> &nums, int k)
    {
        int n = nums.size();
        int diff = *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end());
        if (diff <= 2 * k)
            return 0;
        return diff - 2 * k;
    }
};
// @lc code=end
