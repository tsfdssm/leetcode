/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的K对数字
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<int> tmp(2);
        vector<vector<int>> res;
        tmp[0] = nums1[0];
        tmp[1] = nums2[0];
        int i = 0, j = 0;
        int m = nums1.size();
        int n = nums2.size();
        while (i < m && j < n)
        {
        }
    }
};
// @lc code=end
