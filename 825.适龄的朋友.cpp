/*
 * @lc app=leetcode.cn id=825 lang=cpp
 *
 * [825] 适龄的朋友
 */

// @lc code=start
class Solution
{
public:
    int numFriendRequests(vector<int> &ages)
    {
        sort(ages.begin(), ages.end());
        int n = ages.size();
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            int a = ages[i];
            auto l = upper_bound(ages.begin(), ages.end(), a / 2 + 7);
            auto r = upper_bound(ages.begin(), ages.end(), a);
            if (l < r)
                res += r - l - 1;
        }
        return res;
    }
};
// @lc code=end
