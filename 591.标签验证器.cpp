/*
 * @lc app=leetcode.cn id=591 lang=cpp
 *
 * [591] 标签验证器
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string code)
    {
        int len = code.size();
        bool t = false;
        stack<string> sta;
        for (int i = 0; i < len; ++i)
        {
            if (!i && code[i] != '<')
                return false;
            if (code[i] == '<')
            {
                if (i == len - 1)
                    return false;
                else if (code[i + 1] == '/')
                {
                    i += 2;
                    int j = i;
                    while (i < len && code[i] != '>')
                    {
                        if (code[i] < 'A' || code[i] > 'Z')
                            return false;
                        ++i;
                    }
                    if (i == len || sta.empty())
                        return false;
                    if (sta.top() == code.substr(j, i - j))
                    {
                        sta.pop();
                        if (sta.empty() && i != len - 1)
                            return false;
                    }
                    else
                        return false;
                }
                else if (code[i + 1] == '!')
                {
                    ++i;
                    if (sta.empty())
                        return false;
                    if (code.substr(i, 8) != "![CDATA[")
                        return false;
                    else
                    {
                        while (i < len && code.substr(i - 2, 3) != "]]>")
                        {
                            ++i;
                        }
                        if (i == len)
                            return false;
                    }
                }
                else
                {
                    ++i;
                    int j = i;
                    while (i < len && code[i] != '>')
                    {
                        if (code[i] < 'A' || code[i] > 'Z')
                            return false;
                        ++i;
                    }
                    if (i == len)
                        return false;
                    else
                    {
                        string x = code.substr(j, i - j);
                        if (x.size() < 1 || x.size() > 9)
                            return false;
                        sta.push(x);
                        t = true;
                    }
                }
            }
        }
        return sta.empty() && t;
    }
};

// @lc code=end
