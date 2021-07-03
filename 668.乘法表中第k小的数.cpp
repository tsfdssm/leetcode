/*
 * @lc app=leetcode.cn id=668 lang=cpp
 *
 * [668] 乘法表中第k小的数
 */

// @lc code=start
class Solution
{
public:
    int func(int m, int n, int num)
    {
        int cnt = 0;
        for (int i = 1; i <= m; ++i)
            cnt += min(num / i, n);
        return cnt;
    }
    int findKthNumber(int m, int n, int k)
    {
        if (1 == k)
            return 1;
        if (m * n == k)
            return m * n;
        int l = 1, r = m * n;
        while (l < r)
        {
            int mid = l + (r - l) / 2;
            if (func(m, n, mid) >= k)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};
// @lc code=end
