/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
class Solution
{
public:
    bool isPrim(int x)
    {
        if (1 == x || 0 == x)
            return false;
        if (2 == x || 3 == x)
            return true;
        int t = 2;
        while (t * t <= x)
        {
            if (0 == x % t)
                return false;
            ++t;
        }
        return true;
    }
    int countPrimes(int n)
    {
        int cnt = 0;
        int cur = 2;
        while (cur < n)
        {
            if (isPrim(cur))
                ++cnt;
            ++cur;
        }
        return cnt;
    }
};
// @lc code=end
