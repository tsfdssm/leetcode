/*
 * @lc app=leetcode.cn id=806 lang=cpp
 *
 * [806] 写字符串需要的行数
 */

// @lc code=start
class Solution
{
public:
    vector<int> numberOfLines(vector<int> &widths, string s)
    {
        int line = 1;
        int cnt = 0;
        for (char c : s)
        {
            int tmp = widths[c - 'a'];
            if (tmp + cnt <= 100)
            {
                cnt += tmp;
            }
            else
            {
                line++;
                cnt = tmp;
            }
        }
        return {line, cnt};
    }
};
// @lc code=end
