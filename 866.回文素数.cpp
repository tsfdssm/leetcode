/*
 * @lc app=leetcode.cn id=866 lang=cpp
 *
 * [866] 回文素数
 */

// @lc code=start
class Solution
{
public:
    bool isPrime(int x)
    {
        if (x < 2)
            return false;
        for (int i = 2; i * i <= x; ++i)
        {
            if (x % i == 0)
                return false;
        }
        return true;
    }

    bool isPal(const string &s)
    {
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            if (s[l] != s[r])
                return false;
            ++l;
            --r;
        }
        return true;
    }
    int primePalindrome(int n)
    {
        const int maxn = 2 * 1e8;
        for (int i = n; i < maxn; ++i)
        {
            if (10000000 < i && i < 100000000)
                i = 100000000;
            if (!isPrime(i))
                continue;
            string tmp = to_string(i);
            if (0 == tmp.size() % 2)
            {
                if (11 == i)
                    return 11;
                continue;
            }
            if (isPal(tmp))
                return i;
        }
        return -1;
    }
};
// @lc code=end
