/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */

// @lc code=start
class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int maxn = 0;
        for (int num : nums)
            mp[num]++;
        for (auto it = mp.begin(); it != mp.end(); ++it)
            maxn = max(maxn, it->second);

        unordered_map<int, int> st;
        unordered_map<int, int> ed;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (mp[nums[i]] != maxn)
                continue;
            if (!st.count(nums[i]))
                st[nums[i]] = i;
            ed[nums[i]] = i;
        }
        int res = INT_MAX;
        for (auto &it : mp)
            if (it.second == maxn)
                res = min(res, ed[it.first] - st[it.first] + 1);
        return res;
    }
};
// @lc code=end
