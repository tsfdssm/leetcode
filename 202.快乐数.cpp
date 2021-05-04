/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution
{
public:
    long long happy(long long x)
    {
        long long sum = 0;

        while (x > 0)
        {
            sum += ((x % 10) * (x % 10));
            x /= 10;
        }
        return sum;
    }
    bool isHappy(int n)
    {
        unordered_set<long> hash;
        long long x = n;
        while (x < INT_MAX)
        {
            if (0 == hash.count(x))
                hash.insert(x);
            else
            {
                return false;
            }
            if (1 == x)
                return true;
            x = happy(x);
        }
        return false;
    }
};
// @lc code=end
