/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 */

// @lc code=start
class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        //vector<int> dp(n + 1, 0);
        unordered_map<int, pair<int, int>> mp;
        int sum = 0;
        mp[0] = {-1, -1};
        for (int i = 0; i < n; ++i)
        {
            sum = sum + (nums[i] == 1 ? 1 : -1);
            if (mp.count(sum))
            {
                mp[sum].second = i;
            }
            else
            {
                mp[sum] = {i, i};
            }
        }
        int res = 0;
        for (auto &it : mp)
        {
            auto cur = it.second;
            res = max(res, cur.second - cur.first);
        }
        return res;
    }
};
// @lc code=end
