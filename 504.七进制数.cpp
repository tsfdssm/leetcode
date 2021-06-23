/*
 * @lc app=leetcode.cn id=504 lang=cpp
 *
 * [504] 七进制数
 */

// @lc code=start
class Solution
{
public:
    string convertToBase7(int num)
    {
        bool flag = true;
        if (0 == num)
            return "0";
        if (num < 0)
        {
            num = -num;
            flag = false;
        }
        int k = 0;
        string res;
        while (num > 0)
        {
            k = num % 7;
            res.push_back(k + '0');
            num /= 7;
        }
        if (!flag)
            res.push_back('-');
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
