/*
 * @lc app=leetcode.cn id=821 lang=cpp
 *
 * [821] 字符的最短距离
 */

// @lc code=start
class Solution
{
public:
    vector<int> shortestToChar(const string &s, char c)
    {

        set<int> st;
        int n = s.size();
        vector<int> res(n);
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == c)
                st.insert(i);
        }
        int idx = 0;
        auto nxt = st.begin();
        while (idx <= *nxt)
        {
            res[idx] = *nxt - idx;
            ++idx;
        }
        ++nxt;
        auto last = st.begin();
        while (nxt != st.end())
        {
            if (idx <= *nxt)
            {
                res[idx] = min(*nxt - idx, idx - *last);
                ++idx;
            }
            else
            {
                ++last;
                ++nxt;
            }
        }
        while (idx < n)
        {
            res[idx] = idx - *last;
            ++idx;
        }
        return res;
    }
};
// @lc code=end
