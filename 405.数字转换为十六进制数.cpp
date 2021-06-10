/*
 * @lc app=leetcode.cn id=405 lang=cpp
 *
 * [405] 数字转换为十六进制数
 */

// @lc code=start
class Solution
{
public:
    string toHex(int num)
    {
        if (0 == num)
            return "0";
        string res;
        int mask = 0b1111;
        for (int i = 0; i < 8; ++i)
        {

            int tmp = num & (mask);
            num >>= 4;
            if (10 > tmp)
            {
                res.push_back(tmp + '0');
            }
            else
            {
                res.push_back(tmp - 10 + 'a');
            }
        }
        reverse(res.begin(), res.end());
        int st = 0;
        while (st < res.size() && res[st] == '0')
            ++st;
        return res.substr(st);
    }
};
// @lc code=end
