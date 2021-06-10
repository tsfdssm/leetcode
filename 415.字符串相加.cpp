/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int m = num1.size();
        int n = num2.size();
        int over = 0;

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int i = 0, j = 0;
        string res;
        while (i < m || j < n || over > 0)
        {
            int n1 = i < m ? num1[i] - '0' : 0;
            int n2 = j < n ? num2[j] - '0' : 0;
            int resn = n1 + n2 + over;
            res.push_back(resn % 10 + '0');
            over = resn / 10;
            if (i < m)
                ++i;
            if (j < n)
                ++j;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
