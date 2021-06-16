/*
 * @lc app=leetcode.cn id=462 lang=cpp
 *
 * [462] 最少移动次数使数组元素相等 II
 */

// @lc code=start
class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        int n = nums.size();
        int mid = n / 2;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        int res = 0;
        for (const auto num : nums)
        {
            res += abs(num - nums[mid]);
        }
        return res;
        // long long sum = 0;
        // int n = nums.size();
        // sum = accumulate(nums.begin(), nums.end(), 0);
        // int aver = sum / n;
        // int over = sum % n;
        // if (over > (n / 2))
        //     ++aver;
        // int res = 0;
        // for (const int num : nums)
        // {
        //     res += abs(num - aver);
        // }
        // return res;
    }
};
// @lc code=end
