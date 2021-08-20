/*
 * @lc app=leetcode.cn id=929 lang=cpp
 *
 * [929] 独特的电子邮件地址
 */

// @lc code=start
class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        set<string> st;
        for (string &s : emails)
        {
            int n = s.size();
            string tmp;
            for (int i = 0; i < n; ++i)
            {
                if ('.' == s[i])
                {
                    continue;
                }
                else if ('+' == s[i])
                {
                    int j = i + 1;
                    while (j < n && s[j] != '@')
                        ++j;
                    i = j - 1;
                }
                else if ('@' == s[i])
                {
                    tmp += s.substr(i);
                    break;
                }
                else
                {
                    tmp += s[i];
                }
            }
            st.insert(tmp);
        }
        return st.size();
    }
};
// @lc code=end
