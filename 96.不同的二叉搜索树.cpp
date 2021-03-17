/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution
{
public:
    int numTrees(int n)
    {
        if (0 == n || 1 == n || n < 0)
            return 1;
        vector<int> num(n + 1, 0);
        num[0] = 1;
        num[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
                num[i] += num[j - 1] * num[i - j];
        }
        return num[n];
    }
};
// @lc code=end
