/*
 * @lc app=leetcode.cn id=753 lang=cpp
 *
 * [753] 破解保险箱
 */

// @lc code=start
class Solution
{
public:
    string crackSafe(int n, int k)
    {
        int nk = pow(k, n), nk_l = pow(k, n - 1), num[nk_l];
        fill(num, num + nk_l, k - 1);
        string s(nk + n - 1, '0');
        for (int i = n - 1, node = 0; i < s.size(); ++i)
        {
            s[i] = num[node]-- + '0';
            node = node * k - (s[i - n + 1] - '0') * nk_l + s[i] - '0';
        }
        return s;
    }
};
// @lc code=end
