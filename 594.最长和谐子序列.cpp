/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */

// @lc code=start
class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        map<int, int> mp;
        for (int num : nums)
            mp[num]++;
        auto it1 = mp.begin();
        auto it2 = it1;
        ++it2;
        int res = 0;
        while (it2 != mp.end())
        {
            if (it2->first == it1->first + 1)
                res = max(res, it1->second + it2->second);
            ++it1;
            ++it2;
        }
        return res;
    }
};
// @lc code=end
