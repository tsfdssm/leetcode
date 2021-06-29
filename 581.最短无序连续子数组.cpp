/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

// @lc code=start
class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int res = 0;
        int n = nums.size();
        int l = 0, r = n - 1;
        vector<int> s = nums;
        sort(s.begin(), s.end());
        while (l <= r)
        {
            int flag = 0;
            if (s[l] == nums[l])
                ++l;
            else
                flag++;
            if (s[r] == nums[r])
                --r;
            else
                flag++;
            if (2 == flag)
                return r - l + 1;
        }
        return 0;
    }
};
// @lc code=end
