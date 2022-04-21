/*
 * @lc app=leetcode.cn id=1089 lang=cpp
 *
 * [1089] 复写零
 *
 * https://leetcode-cn.com/problems/duplicate-zeros/description/
 *
 * algorithms
 * Easy (58.18%)
 * Likes:    113
 * Dislikes: 0
 * Total Accepted:    22.4K
 * Total Submissions: 38.6K
 * Testcase Example:  '[1,0,2,3,0,4,5,0]'
 *
 * 给你一个长度固定的整数数组 arr，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移。
 *
 * 注意：请不要在超过该数组长度的位置写入元素。
 *
 * 要求：请对输入的数组 就地 进行上述修改，不要从函数返回任何东西。
 *
 *
 *
 * 示例 1：
 *
 * 输入：[1,0,2,3,0,4,5,0]
 * 输出：null
 * 解释：调用函数后，输入的数组将被修改为：[1,0,0,2,3,0,0,4]
 *
 *
 * 示例 2：
 *
 * 输入：[1,2,3]
 * 输出：null
 * 解释：调用函数后，输入的数组将被修改为：[1,2,3]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= arr.length <= 10000
 * 0 <= arr[i] <= 9
 *
 *
 */

// @lc code=start
class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> vis(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; ++i)
        {
            if (i + 1 + cnt >= n)
                break;
            if (arr[i] == 0)
            {
                ++cnt;
                vis[i] = 1;
            }
        }
        int l = n - cnt - 1;
        int r = n - 1;
        for (; r >= 0;)
        {
            if (vis[l] == 1)
            {
                arr[r--] = 0;
            }
            arr[r--] = arr[l--];
        }
        return;
    }
};
// @lc code=end
