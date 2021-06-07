/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution
{
public:
    string decodeString(string s)
    {
        stack<int> nums;
        stack<string> ss;
        int n = s.size();
        //string tmp;
        ss.push("");
        int index = 0;
        while (index < n)
        {
            char c = s[index];
            if (isDigit(c))
            {
                int ed = index + 1;
                long long num = c - '0';
                while (ed < n && isDigit(s[ed]))
                {
                    num *= 10;
                    num += s[ed] - '0';
                    ++ed;
                }
                index = ed + 1;
                nums.push(num);
                ss.push("");
            }
            else if (isChar(c))
            {
                ss.top() += c;
                ++index;
            }
            else
            {
                string tmp = ss.top();
                for (int i = 1; i < nums.top(); ++i)
                    tmp += ss.top();
                ss.pop();
                nums.pop();
                ss.top() += tmp;
                ++index;
            }
        }
        return ss.top();
    }

    inline bool isDigit(char c)
    {
        return '0' <= c && c <= '9';
    }
    inline bool isChar(char c)
    {
        return 'a' <= c && c <= 'z';
    }
};
// @lc code=end
