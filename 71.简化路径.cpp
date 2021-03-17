/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution
{
public:
    string simplifyPath(string path)
    {
        stack<string> st;
        path += "/";
        string tmp;
        for (auto c : path)
        {
            if ('/' == c)
            {
                if (".." == tmp && !st.empty())
                {
                    st.pop();
                }
                else if (".." != tmp && "." != tmp && !tmp.empty())
                {
                    st.push(tmp);
                }
                tmp.clear();
            }
            else
            {
                tmp += c;
            }
        }
        string res;
        while (!st.empty())
        {
            string s = st.top();
            st.pop();
            res = "/" + s + res;
        }
        if (res.empty())
            return "/";
        return res;
    }
};
// @lc code=end
