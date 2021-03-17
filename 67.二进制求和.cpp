/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string res;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int n = max(a.size(), b.size());
        int tmp = 0;
        for (int i = 0; i < n; i++)
        {
            tmp += (i < a.size()) ? a[i] == '1' : 0;
            tmp += (i < b.size()) ? b[i] == '1' : 0;
            res.push_back(tmp % 2 == 0 ? '0' : '1');
            tmp /= 2;
        }
        if (tmp == 1)
            res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
