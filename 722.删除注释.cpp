/*
 * @lc app=leetcode.cn id=722 lang=cpp
 *
 * [722] 删除注释
 */

// @lc code=start
class Solution
{
public:
    vector<string> removeComments(vector<string> &source)
    {
        bool isComment = false;
        vector<string> res;
        string cur = "";
        for (string s : source)
        {
            int i = 0;
            if (!isComment)
                cur = "";
            int n = s.size();
            while (i < n)
            {
                if (!isComment && i < n - 1 && s[i] == '/' && s[i + 1] == '*')
                {
                    isComment = true;
                    ++i;
                }
                else if (isComment && i < n - 1 && s[i] == '*' && s[i + 1] == '/')
                {
                    isComment = false;
                    ++i;
                }
                else if (!isComment && i < n - 1 && s[i] == '/' && s[i + 1] == '/')
                    break;
                else if (!isComment)
                    cur += s[i];
                ++i;
            }
            if (!isComment && !cur.empty())
                res.push_back(cur);
        }
        return res;
    }
};
// @lc code=end
