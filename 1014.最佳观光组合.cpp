/*
 * @lc app=leetcode.cn id=1014 lang=cpp
 *
 * [1014] 最佳观光组合
 */

// @lc code=start
class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int n = values.size();

        int maxn = values[0];
        int res = 0;
        for (int i = 1; i < n; ++i)
        {
            res = max(res, maxn + values[i] - i);
            maxn = max(maxn, values[i] + i);
        }
        return res;

        // int l = 0;
        // int r = n - 1;
        // int res = 0;

        // auto check = [&](int i, int j) -> bool {
        //     return values[i + 1] - values[i] >= values[j - 1] - values[j];
        // };
        // while (l < r)
        // {
        //     res = max(res, values[l] + values[r] + l - r);
        //     if (check(l, r))
        //     {
        //         ++l;
        //     }
        //     else
        //     {
        //         --r;
        //     }
        // }
        // return res;
    }
};
// @lc code=end
