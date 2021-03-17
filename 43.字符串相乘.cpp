/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";
        int m = num1.size(), n = num2.size();
        auto resArr = vector<int>(m + n);
        for (int i = m - 1; i >= 0; i--)
        {
            int x = num1.at(i) - '0';
            for (int j = n - 1; j >= 0; j--)
            {
                int y = num2.at(j) - '0';
                resArr[i + j + 1] += x * y;
            }
        }
        for (int i = m + n - 1; i > 0; i--)
        {
            resArr[i - 1] += resArr[i] / 10;
            resArr[i] %= 10;
        }
        int index = resArr[0] == 0 ? 1 : 0;
        string res;
        while (index < m + n)
        {
            res.push_back(resArr[index] + '0');
            index++;
        }
        return res;
    }
};
// @lc code=end
