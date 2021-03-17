/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> res;
        for (int binary = 0; binary < 1 << n; binary++)
        {
            res.push_back(binary ^ binary >> 1);
        }
        return res;
    }
};
// @lc code=end
