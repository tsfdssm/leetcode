/*
 * @lc app=leetcode.cn id=372 lang=cpp
 *
 * [372] 超级次方
 */

// @lc code=start
int base = 1337;
class Solution
{
public:
    int superPow(int a, vector<int> &b)
    {
        if (b.empty())
            return 1;
        a %= base;
        int k = b.back();
        b.pop_back();
        int part1 = m_pow(a, k);
        int part2 = m_pow(superPow(a, b), 10);
        return (part1 * part2) % base;
    }
    int m_pow(int x, int p)
    {
        x %= base;
        int res = 1;
        for (int i = 0; i < p; ++i)
        {
            res *= x;
            res %= base;
        }
        return res;
    }
};
// @lc code=end
