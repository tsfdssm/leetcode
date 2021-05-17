/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        vector<int> cnt(n + 1);
        for (int i : citations)
            cnt[min(i, n)]++;
        for (int i = n; i >= 0; --i)
        {
            if (i != n)
                cnt[i] += cnt[i + 1];
            if (cnt[i] >= i)
                return i;
        }
        return 0;
    }
};
// @lc code=end
