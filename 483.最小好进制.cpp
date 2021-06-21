/*
 * @lc app=leetcode.cn id=483 lang=cpp
 *
 * [483] 最小好进制
 */

// @lc code=start
class Solution
{
public:
    string smallestGoodBase(string n)
    {
        long long val = stol(n);
        int mMax = floor(log(val) / log(2));
        for (int m = mMax; m > 1; --m)
        {
            int k = pow(val, 1.0 / m);
            long mul = 1, sum = 1;
            for (int i = 0; i < m; ++i)
            {
                mul *= k;
                sum += mul;
            }
            if (sum == val)
                return to_string(k);
        }
        return to_string(val - 1);
    }
};
// @lc code=end
