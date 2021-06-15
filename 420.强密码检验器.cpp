/*
 * @lc app=leetcode.cn id=420 lang=cpp
 *
 * [420] 强密码检验器
 */

// @lc code=start
class Solution
{
public:
    int strongPasswordChecker(string s)
    {
        bool mislchar, misdigit, misuchar;
        mislchar = misdigit = misuchar = true;
        for (auto &c : s)
        {
            if (isdigit(c))
                misdigit = false;
            else if (islower(c))
                mislchar = false;
            else if (isupper(c))
                misuchar = false;
        }
        int missnum = mislchar + misuchar + misdigit;

        int done = 0, dtwo = 0, replace = 0;
        for (int i = 2; i < s.size(); i++)
        {
            if (s[i] == s[i - 1] && s[i - 1] == s[i - 2])
            {
                int len = 3;
                while (i + 1 < s.size() && s[i + 1] == s[i])
                {
                    i++;
                    len++;
                }
                if (len % 3 == 0)
                    done++;
                else if (len % 3 == 1)
                    dtwo++;
                replace += len / 3;
            }
        }

        if (s.size() < 6)
            return max(6 - (int)s.size(), missnum);
        else if (s.size() <= 20)
            return max(replace, missnum);
        else
        {
            int del = s.size() - 20;
            // Each deletion can represent one replacement.
            replace -= min(del, done);
            // Two.
            if (del - done > 0)
                replace -= min((del - done) / 2, dtwo);
            // Three.
            if (del - done - 2 * dtwo > 0)
                replace -= (del - done - 2 * dtwo) / 3;
            return del + max(replace, missnum);
        }
        // int n = password.size();
        // int res = 0;
        // if (n < 6)
        // {
        //     res += 6 - n;
        // }
        // else if (n > 20)
        // {
        //     res += n - 20;
        // }
        // bool hasLower = false;
        // bool hasUpper = false;
        // bool hasDigit = false;

        // char last = password[0];
        // int cnt = 0;
        // for (int i = 0; i < n; ++i)
        // {
        //     char c = password[i];
        //     if (!hasLower && 'a' <= c && c <= 'z')
        //     {
        //         hasLower = true;
        //     }
        //     else if (!hasUpper && 'A' <= c && c <= 'Z')
        //     {
        //         hasUpper = true;
        //     }
        //     else if (!hasDigit && '0' <= c && c <= '9')
        //     {
        //         hasDigit = true;
        //     }
        //     if (0 == i)
        //         continue;
        //     if (password[i - 1] == c)
        //     {
        //         ++cnt;
        //     }
        //     else
        //     {
        //         cnt = 1;
        //     }
        //     if (3 == cnt)
        //     {
        //         ++res;
        //         cnt = 0;
        //     }
        // }
        // return hasLower && hasUpper && hasDigit;
    }
};
// @lc code=end
