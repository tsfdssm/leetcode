/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        if (s.size() % 2 != 0)
            return false;
        stack<char> st;
        for (char c : s)
        {
            switch (c)
            {

            case '{':
            {
                st.push('{');
                break;
            }
            case '[':
            {
                st.push('[');
                break;
            }
            case '(':
            {
                st.push('(');
                break;
            }
            case ')':
            {
                if (!st.empty() && st.top() == '(')
                {
                    st.pop();
                    break;
                }
                return false;
            }
            case ']':
            {
                if (!st.empty() && st.top() == '[')
                {
                    st.pop();
                    break;
                }
                return false;
            }
            case '}':
            {
                if (!st.empty() && st.top() == '{')
                {
                    st.pop();
                    break;
                }
                return false;
            }
            default:
                return false;
            }
        }
        if (st.empty())
            return true;
        else
            return false;
    }
};
// @lc code=end
