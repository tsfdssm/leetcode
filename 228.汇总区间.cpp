/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> res;
        if (0 == nums.size())
            return res;

        int n = nums.size();
        vector<pair<int, int>> seg;
        int last = nums[0];
        for (int i = 0; i < n; ++i)
        {
            if (i != n - 1 && nums[i] == (nums[i + 1] - 1))
                continue;
            seg.emplace_back(make_pair(last, nums[i]));
            if (i != n - 1)
                last = nums[i + 1];
        }
        for (auto &tmp : seg)
        {
            if (tmp.first != tmp.second)
                res.emplace_back(to_string(tmp.first) + "->" + to_string(tmp.second));
            else
                res.emplace_back(to_string(tmp.first));
        }
        return res;
    }
};
// @lc code=end
