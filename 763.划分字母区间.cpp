/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        map<char, int> st;
        map<char, int> ed;
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            char c = s[i];
            if (!st.count(c))
                st[c] = i;
            ed[c] = i;
        }
        int pos = 0;
        vector<int> res;
        while (pos < n)
        {
            int maxEnd = ed[s[pos]];
            for (int i = pos + 1; i < maxEnd; ++i)
            {
                maxEnd = max(maxEnd, ed[s[i]]);
            }
            // for (auto it = st.begin(); it != st.end(); ++it)
            // {
            //     if (it->second < maxEnd && ed[it->first] > maxEnd)
            //     {
            //         maxEnd = ed[it->first];
            //         it = st.begin();
            //     }
            // }
            for (auto it = st.begin(); it != st.end();)
            {
                if (it->second < maxEnd)
                {
                    ed.erase(it->first);
                    it = st.erase(it);
                }
                else
                {
                    ++it;
                }
            }
            res.emplace_back(maxEnd - pos + 1);
            pos = maxEnd + 1;
        }
        return res;
    }
};
// @lc code=end
