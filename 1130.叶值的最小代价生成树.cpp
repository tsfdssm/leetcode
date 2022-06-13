/*
 * @lc app=leetcode.cn id=1130 lang=cpp
 *
 * [1130] 叶值的最小代价生成树
 *
 * https://leetcode.cn/problems/minimum-cost-tree-from-leaf-values/description/
 *
 * algorithms
 * Medium (63.99%)
 * Likes:    234
 * Dislikes: 0
 * Total Accepted:    7.4K
 * Total Submissions: 11.5K
 * Testcase Example:  '[6,2,4]'
 *
 * 给你一个正整数数组 arr，考虑所有满足以下条件的二叉树：
 *
 *
 * 每个节点都有 0 个或是 2 个子节点。
 * 数组 arr 中的值与树的中序遍历中每个叶节点的值一一对应。（知识回顾：如果一个节点有 0 个子节点，那么该节点为叶节点。）
 * 每个非叶节点的值等于其左子树和右子树中叶节点的最大值的乘积。
 *
 *
 * 在所有这样的二叉树中，返回每个非叶节点的值的最小可能总和。这个和的值是一个 32 位整数。
 *
 *
 *
 * 示例：
 *
 * 输入：arr = [6,2,4]
 * 输出：32
 * 解释：
 * 有两种可能的树，第一种的非叶节点的总和为 36，第二种非叶节点的总和为 32。
 *
 * ⁠   24            24
 * ⁠  /  \          /  \
 * ⁠ 12   4        6    8
 * ⁠/  \               / \
 * 6    2             2   4
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= arr.length <= 40
 * 1 <= arr[i] <= 15
 * 答案保证是一个 32 位带符号整数，即小于 2^31。
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int mctFromLeafValues(vector<int> &arr)
    {
        int n = arr.size();
        const int inf = 0x3f3f3f3f;
        vector<vector<int>> maxn(n, vector<int>(n, 0));
        vector<vector<int>> dp(n, vector<int>(n, inf));

        for (int i = 0; i < n; ++i)
        {
            maxn[i][i] = arr[i];
            for (int j = i + 1; j < n; ++j)
                maxn[i][j] = max(maxn[i][j - 1], arr[j]);
        }

        for (int i = 0; i < n; ++i)
            dp[i][i] = 0;
        for (int len = 2; len <= n; ++len)
            for (int i = 0; i <= n - len; ++i)
            {
                int j = i + len - 1;
                for (int k = i + 1; k <= j; ++k)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k][j] + (maxn[i][k - 1] * maxn[k][j]));
                }
            }

        return dp[0][n - 1];
    }
};
// @lc code=end
