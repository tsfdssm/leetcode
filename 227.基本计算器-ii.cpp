/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
class Solution
{
public:
    int calculate(string s)
    {
        if (0 == s.size())
            return 0;

        stack<char, vector<char>> st_op;
        stack<int, vector<int>> st_num;
        st_op.push('#');

        if ('+' == s[0] || '-' == s[0])
            s = "0" + s;
        int n = s.size();

        auto calculate = [&]() -> void {
            //st_num.push(st_op.top());
            int tmp2 = st_num.top();
            st_num.pop();

            char op = st_op.top();
            if ('+' == op)
                st_num.top() += tmp2;
            else if ('-' == op)
                st_num.top() -= tmp2;
            else if ('*' == op)
                st_num.top() *= tmp2;
            else if ('/' == op)
                st_num.top() /= tmp2;

            st_op.pop();
            return;
        };
        for (int i = 0; i < n; ++i)
        {
            char c = s[i];
            if ('(' == c)
            {
                st_op.push('(');
            }
            else if (')' == c)
            {
                while (st_op.top() != '(')
                {
                    calculate();
                }
                st_op.pop();
            }
            else if (isNum(c))
            {
                if ('0' == c && i + 1 < n && isNum(s[i + 1]))
                    error();
                int now = c - '0';
                int j = i + 1;
                while (j < n && isNum(s[j]))
                {
                    now *= 10;
                    now += (s[j] - '0');
                    ++j;
                }
                i = j - 1;
                st_num.push(now);
            }
            else if (isOperator(c))
            {
                while (st_op.top() != '(' && opLevel(st_op.top()) >= opLevel(c))
                {
                    calculate();
                }
                if (i - 1 >= 0 && '(' == s[i - 1])
                    st_num.push(0);
                st_op.push(c);
            }
            else
            {
            }
        }
        while ('#' != st_op.top())
        {
            calculate();
        }
        return st_num.top();
    }
    inline bool isNum(const char c) noexcept
    {
        return '0' <= c && c <= '9';
    }

    inline bool isOperator(const char c) noexcept
    {
        return '+' == c || '-' == c || '*' == c || '/' == c;
    }

    inline int opLevel(const char c) noexcept
    {
        if ('#' == c)
            return -1;
        if ('*' == c || '/' == c)
            return 1;
        return 0;
    }
    inline void error() noexcept
    {
    }
};
// @lc code=end
