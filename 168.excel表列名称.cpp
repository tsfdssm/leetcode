/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string res;
        //columnNumber -= 1;
        while (columnNumber > 0)
        {
            columnNumber--;
            res.push_back('A' + (columnNumber) % 26);
            columnNumber /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
