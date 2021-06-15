/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> s_c(26, 0);
        vector<int> p_c(26, 0);

        for (char c : p)
        {
            p_c[c - 'a']++;
        }
        int l, r = l = 0;
        int n = s.size();
        int k = p.size();
        vector<int> res;
        while (r < n)
        {

            s_c[s[r] - 'a']++;
            ++r;
            if (k == r - l)
            {
                if (s_c == p_c)
                    res.push_back(l);
                s_c[s[l] - 'a']--;
                ++l;
            }
        }
        return res;
    }
};
// @lc code=end
