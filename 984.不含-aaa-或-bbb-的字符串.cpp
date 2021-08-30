/*
 * @lc app=leetcode.cn id=984 lang=cpp
 *
 * [984] 不含 AAA 或 BBB 的字符串
 */

// @lc code=start
class Solution
{
public:
    string solve(int a, int b, char ac, char bc)
    {
        int seg = (a + 1) / 2;
        if (b < seg - 1)
            return "";
        int segb2 = b - seg + 1;
        string res;

        for (int i = 0; i < seg; ++i)
        {
            if (a > 0)
            {
                res += ac;
                --a;
            }
            if (a > 0)
            {
                res += ac;
                --a;
            }
            if (b > 0)
            {
                res += bc;
                --b;
            }
            if (i < segb2 && b > 0)
            {
                res += bc;
                --b;
            }
        }
        return res;
    }
    string strWithout3a3b(int a, int b)
    {
        if (a < b)
            return solve(b, a, 'b', 'a');
        return solve(a, b, 'a', 'b');
    }
};
// @lc code=end
