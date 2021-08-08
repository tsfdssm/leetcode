/*
 * @lc app=leetcode.cn id=838 lang=cpp
 *
 * [838] 推多米诺
 */

// @lc code=start
class Solution
{
public:
    string pushDominoes(const string &s)
    {
        int n = s.size();
        string res;
        for (int i = 0; i < n; ++i)
        {
            int j = i;
            while (j < n && s[j] == '.')
                ++j;
            if (n == j)
            {
                res += string(n - i, '.');
                break;
            }
            if (s[j] == 'L')
            {
                res += string(j - i + 1, 'L');
                i = j;
            }
            else
            {
                res += string(j - i, '.');
                int k = j + 1;
                while (k < n)
                {
                    if (s[k] == '.')
                        ++k;
                    else if ('R' == s[k])
                    {
                        res += string(k - j, 'R');
                        j = k;
                        ++k;
                    }
                    else
                    {
                        res += string((k + 1 - j) / 2, 'R');
                        if ((k - j - 1) % 2 == 1)
                            res += '.';
                        res += string((k + 1 - j) / 2, 'L');
                        break;
                    }
                }
                if (k == n)
                {
                    res += string(n - j, 'R');
                    break;
                }
                i = k;
            }
        }
        return res;
    }
};
// @lc code=end
