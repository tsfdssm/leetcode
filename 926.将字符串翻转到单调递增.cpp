/*
 * @lc app=leetcode.cn id=926 lang=cpp
 *
 * [926] 将字符串翻转到单调递增
 */

// @lc code=start
class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int n = s.size();
        vector<int> pre(n, 0);
        vector<int> nxt(n, 0);

        pre[0] = s[0] - '0';
        for (int i = 1; i < n; ++i)
        {
            pre[i] = pre[i - 1];
            if ('1' == s[i])
                pre[i]++;
        }
        nxt[n - 1] = '1' - s[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            nxt[i] = nxt[i + 1];
            if ('0' == s[i])
                nxt[i]++;
        }

        int res = min(nxt[0], pre[n - 1]);
        for (int i = 0; i < n - 1; ++i)
        {
            res = min(res, pre[i] + nxt[i + 1]);
        }
        return res;
    }
};
// @lc code=end
