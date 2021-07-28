/*
 * @lc app=leetcode.cn id=801 lang=cpp
 *
 * [801] 使序列递增的最小交换次数
 */

// @lc code=start
class Solution
{
public:
    int minSwap(vector<int> &a, vector<int> &b)
    {
        int n = a.size();
        int n1 = 0, s1 = 1;
        for (int i = 1; i < n; ++i)
        {
            int n2 = INT_MAX;
            int s2 = INT_MAX;
            if (a[i - 1] < a[i] && b[i - 1] < b[i])
            {
                n2 = n1;
                s2 = s1 + 1;
            }
            if (a[i - 1] < b[i] && b[i - 1] < a[i])
            {
                n2 = min(n2, s1);
                s2 = min(s2, n1 + 1);
            }
            n1 = n2;
            s1 = s2;
        }
        return min(n1, s1);
    }
};
// @lc code=end
