/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> mpab;
        unordered_map<int, int> mpcd;
        for (const auto &a : nums1)
            for (const auto &b : nums2)
                mpab[a + b]++;
        for (const auto &c : nums3)
            for (const auto &d : nums4)
                mpcd[c + d]++;
        int res = 0;
        for (const auto &it1 : mpab)
            for (const auto &it2 : mpcd)
            {
                if (it1.first == -(it2.first))
                    res += (it1.second * it2.second);
            }
        return res;
    }
};
// @lc code=end
