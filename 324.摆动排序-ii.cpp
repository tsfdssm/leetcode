/*
 * @lc app=leetcode.cn id=324 lang=cpp
 *
 * [324] 摆动排序 II
 */

// @lc code=start
class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        int n = nums.size();
        int m = 0, k = 0;
        if (0 == n % 2)
        {
            k = n >> 1;
        }
        else
        {
            k = (n >> 1) + 1;
        }

        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        vector<int> res(n);
        for (int i = 0, j = 1; i < n && j < n; ++++i, ++++j)
        {
            res[i] = nums[m++];
            res[j] = nums[k++];
        }
        if (1 == n % 2)
            res[n - 1] = nums[m];
        nums.assign(res.begin(), res.end());
    }
};
// @lc code=end
