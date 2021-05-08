/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 */

// @lc code=start
class Solution
{
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        //if (A > C || B > D || E > G || F > H)
        //    return 0;
        if (E < A)
            return computeArea(E, F, G, H, A, B, C, D);
        int sum = (C - A) * (D - B) + (G - E) * (H - F);
        if (B >= H || D <= F || C <= E)
            return sum;
        sum -= (min(C, G) - E) * (min(D, H) - max(B, F));
        return sum;
    }
};
// @lc code=end
