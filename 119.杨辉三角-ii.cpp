/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> res(rowIndex + 1);
        res[0] = 1;
        for (int i = 1; i <= rowIndex; ++i)
            res[i] = 1LL * res[i - 1] * (rowIndex - i + 1) / i;
        return res;
    }
};
// @lc code=end
