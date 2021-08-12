/*
 * @lc app=leetcode.cn id=899 lang=cpp
 *
 * [899] 有序队列
 */

// @lc code=start
class Solution
{
public:
    bool inline check(const string &s, int l, int r)
    {
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            if (s[(l + i) % n] == s[(r + i) % n])
                continue;
            if (s[(l + i) % n] < s[(r + i) % n])
                return true;
            else
                return false;
        }
        return false;
    }
    string orderlyQueue(string s, int k)
    {
        if (1 == k)
        {
            int n = s.size();
            int idx = 0;
            for (int i = 1; i < n; ++i)
            {
                if (check(s, i, idx))
                    idx = i;
            }
            string res = s.substr(idx) + s.substr(0, idx);
            return res;
        }
        else
        {
            sort(s.begin(), s.end());
            // vector<int> cnt(26, 0);
            // for (char c : s)
            // {
            //     cnt[c - 'a']++;
            // }
            // string res;
            // for (int i = 0; i < 26; ++i)
            // {
            //     res += string(cnt[i], 'a' + i);
            // }
            return s;
        }
    }
};
// @lc code=end
