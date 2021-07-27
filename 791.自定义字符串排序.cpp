/*
 * @lc app=leetcode.cn id=791 lang=cpp
 *
 * [791] 自定义字符串排序
 */

// @lc code=start
class Solution
{
public:
    string customSortString(string order, string s)
    {
        int n = order.size();
        vector<int> cnt(n, 0);
        unordered_map<char, int> mp;
        for (int i = 0; i < n; ++i)
            mp[order[i]] = i;
        string res;
        for (char c : s)
        {
            if (!mp.count(c))
                res += c;
            else
                cnt[mp[c]]++;
        }
        for (int i = 0; i < n; ++i)
        {
            while (cnt[i] > 0)
            {
                res += order[i];
                cnt[i]--;
            }
        }
        return res;
    }
};
// @lc code=end
