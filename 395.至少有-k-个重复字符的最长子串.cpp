/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有 K 个重复字符的最长子串
 */

// @lc code=start
class Solution
{
public:
    int longestSubstring(string s, int k)
    {

        vector<int> chars(26, 0);
        for (char c : s)
            chars[c - 'a']++;
        int kind = 0;
        for (int i : chars)
            if (i >= k)
                ++kind;

        int res = 0;
        int n = s.size();
        for (int t = 1; t <= kind; ++t)
        {
            int l = 0, r = 0;
            vector<int> cnt(26, 0);
            int total = 0;
            int less = 0;
            while (r < n)
            {
                cnt[s[r] - 'a']++;
                if (1 == cnt[s[r] - 'a'])
                {
                    ++total;
                    ++less;
                }
                if (k == cnt[s[r] - 'a'])
                {
                    --less;
                }
                while (total > t)
                {
                    cnt[s[l] - 'a']--;
                    if (0 == cnt[s[l] - 'a'])
                    {
                        --total;
                        --less;
                    }
                    if ((k - 1) == cnt[s[l] - 'a'])
                    {
                        ++less;
                    }
                    ++l;
                }
                if (0 == less)
                    res = max(res, r - l + 1);
                ++r;
            }
        }
        return res;
    }
};
// @lc code=end
