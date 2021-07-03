/*
 * @lc app=leetcode.cn id=658 lang=cpp
 *
 * [658] 找到 K 个最接近的元素
 */

// @lc code=start
class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        sort(arr.begin(), arr.end(), [&](const auto &a, const auto &b) { return abs(a - x) < abs(b - x) || (abs(a - x) == abs(b - x) && a < b); });
        vector<int> res = vector<int>(arr.begin(), arr.begin() + k);
        sort(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
