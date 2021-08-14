/*
 * @lc app=leetcode.cn id=906 lang=cpp
 *
 * [906] 超级回文数
 */

// @lc code=start
class Solution
{
public:
    int superpalindromesInRange(string left, string right)
    {
        int res = 0;
        long l = stol(left);
        long r = stol(right);
        for (int i = 1; i < 100000; ++i)
        {
            string s = to_string(i);
            string s2 = s;
            reverse(s2.begin(), s2.end());
            long m = stol(s + s2);
            m *= m;
            if (m > r)
                break;
            else if (m >= l && isPal(m))
                ++res;
        }

        for (int i = 1; i < 100000; ++i)
        {
            string s = to_string(i);
            string s2 = s;
            reverse(s2.begin(), s2.end());
            long m = stol(s.append(s2.begin() + 1, s2.end()));
            m *= m;
            if (m > r)
                break;
            else if (m >= l && isPal(m))
                ++res;
        }
        return res;
    }
    bool isPal(long num)
    {
        long n = num;
        long rev = 0;
        while (n > 0)
        {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return rev == num;
    }
};
// @lc code=end
