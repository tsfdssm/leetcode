/*
 * @lc app=leetcode.cn id=779 lang=cpp
 *
 * [779] 第K个语法符号
 */

// @lc code=start
class Solution
{
public:
    int kthGrammar(int n, int k)
    {
        if (1 == n)
            return 0;
        if (k & 1)
            return kthGrammar(n - 1, (k + 1) / 2);
        return kthGrammar(n - 1, (k + 1) / 2) ^ 1;
    }
};
// @lc code=end
