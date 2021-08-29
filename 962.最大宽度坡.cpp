/*
 * @lc app=leetcode.cn id=962 lang=cpp
 *
 * [962] 最大宽度坡
 */

// @lc code=start
class Solution
{
public:
    int maxWidthRamp(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> minl(n);
        minl[0] = nums[0];
        for (int i = 1; i < n; ++i)
        {
            minl[i] = min(minl[i - 1], nums[i]);
        }
        int res = 0;
        for (int i = 1; i < n; ++i)
        {
            if (minl[i - 1] > nums[i])
                continue;
            int l = 0, r = i - 1;
            while (l < r)
            {
                int mid = l + (r - l) / 2;
                if (minl[mid] > nums[i])
                    l = mid + 1;
                else
                    r = mid;
            }
            res = max(res, i - l);
        }
        return res;
    }
};
// @lc code=end
