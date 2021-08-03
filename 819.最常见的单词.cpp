/*
 * @lc app=leetcode.cn id=819 lang=cpp
 *
 * [819] 最常见的单词
 */

// @lc code=start
class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        map<string, int> mp;
        set<string> st;
        for (string &s : banned)
            st.insert(s);
        int n = paragraph.size();
        for (int i = 0; i < n; ++i)
            if ('A' <= paragraph[i] && paragraph[i] <= 'Z')
                paragraph[i] += 'a' - 'A';
        for (int i = 0; i < n; ++i)
        {
            if (isS(paragraph[i]))
                continue;
            int j = i + 1;
            while (j < n && !isS(paragraph[j]))
                ++j;
            string tmp = paragraph.substr(i, j - i);
            if (!st.count(tmp))
                mp[tmp]++;
            i = j;
        }
        string res;
        int cnt = 0;
        for (auto it = mp.begin(); it != mp.end(); ++it)
        {
            if (it->second > cnt)
            {
                cnt = it->second;
                res = it->first;
            }
        }
        return res;
    }

    inline bool isS(char c)
    {
        return c == '!' || c == '?' || c == '\'' || c == ',' || c == ';' || c == '.' || c == ' ';
    }

    inline bool isC(char c)
    {
        return 'a' <= c && c <= 'z';
    }
};
// @lc code=end
