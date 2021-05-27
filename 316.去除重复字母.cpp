/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
class Solution
{
public:
    string removeDuplicateLetters(string &s)
    {
        vector<int> vis(26), rest(26);
        for (char c : s)
            ++rest[c - 'a'];
        string ans;
        for (char c : s)
        {
            if (!vis[c - 'a'])
            {
                while (!ans.empty() && ans.back() > c && rest[ans.back() - 'a'])
                {
                    vis[ans.back() - 'a'] = 0;
                    ans.pop_back();
                }
                vis[c - 'a'] = 1;
                ans.push_back(c);
            }
            --rest[c - 'a'];
        }

        return ans;
    }
};
// @lc code=end
