/*
 * @lc app=leetcode.cn id=1131 lang=cpp
 *
 * [1131] 绝对值表达式的最大值
 *
 * https://leetcode.cn/problems/maximum-of-absolute-value-expression/description/
 *
 * algorithms
 * Medium (46.47%)
 * Likes:    61
 * Dislikes: 0
 * Total Accepted:    3.7K
 * Total Submissions: 8K
 * Testcase Example:  '[1,2,3,4]\n[-1,4,5,6]'
 *
 * 给你两个长度相等的整数数组，返回下面表达式的最大值：
 *
 * |arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|
 *
 * 其中下标 i，j 满足 0 <= i, j < arr1.length。
 *
 *
 *
 * 示例 1：
 *
 * 输入：arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
 * 输出：13
 *
 *
 * 示例 2：
 *
 * 输入：arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
 * 输出：20
 *
 *
 *
 * 提示：
 *
 *
 * 2 <= arr1.length == arr2.length <= 40000
 * -10^6 <= arr1[i], arr2[i] <= 10^6
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int maxAbsValExpr(vector<int> &arr1, vector<int> &arr2)
    {
        int n = arr1.size();
        int res = 0;
        int minn = arr1[0] + arr2[0];
        for (int i = 1; i < n; ++i)
            res = max(res, arr1[i] + arr2[i] + i - minn), minn = min(minn, arr1[i] + arr2[i] + i);
        minn = arr1[0] - arr2[0];
        for (int i = 1; i < n; ++i)
            res = max(res, arr1[i] - arr2[i] + i - minn), minn = min(minn, arr1[i] - arr2[i] + i);
        minn = -arr1[0] + arr2[0];
        for (int i = 1; i < n; ++i)
            res = max(res, -arr1[i] + arr2[i] + i - minn), minn = min(minn, -arr1[i] + arr2[i] + i);
        minn = -arr1[0] - arr2[0];
        for (int i = 1; i < n; ++i)
            res = max(res, -arr1[i] - arr2[i] + i - minn), minn = min(minn, -arr1[i] - arr2[i] + i);
        return res;
    }
};
// @lc code=end
