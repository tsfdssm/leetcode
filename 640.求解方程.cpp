/*
 * @lc app=leetcode.cn id=640 lang=cpp
 *
 * [640] 求解方程
 */

// @lc code=start
class Solution
{
public:
    string solveEquation(string s)
    {
        int n = s.size();
        int idx = 0;
        while (idx < n && s[idx] != '=')
            ++idx;
        auto [a, b] = get(s.substr(0, idx));
        ++idx;
        auto [c, d] = get(s.substr(idx));
        a -= c;
        d -= b;
        if (0 == a)
        {
            if (0 == d)
                return "Infinite solutions";
            else
                return "No solution";
        }
        else
        {
            d /= a;
            return "x=" + to_string(d);
        }
    }
    pair<int, int> get(const string &s)
    {
        int a = 0;
        int b = 0;
        int n = s.size();
        for (int i = 0; i < n;)
        {
            int j = i + 1;
            while (j < n && s[j] != '-' && s[j] != '+')
                ++j;

            if (s[j - 1] == 'x')
            {
                if (j == i + 1)
                    ++a;
                else if (j == i + 2 && (s[i] == '-' || s[i] == '+'))
                {
                    a += s[i] == '+' ? 1 : -1;
                }
                else
                {
                    a += stoi(s.substr(i, j - 1 - i));
                }
            }
            else
            {
                b += stoi(s.substr(i, j - i));
            }
            i = j;
        }
        return {a, b};
    }
};
// @lc code=end
