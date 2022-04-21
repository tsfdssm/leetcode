/*
 * @lc app=leetcode.cn id=1053 lang=cpp
 *
 * [1053] 交换一次的先前排列
 *
 * https://leetcode-cn.com/problems/previous-permutation-with-one-swap/description/
 *
 * algorithms
 * Medium (46.25%)
 * Likes:    37
 * Dislikes: 0
 * Total Accepted:    6.6K
 * Total Submissions: 14.3K
 * Testcase Example:  '[3,2,1]'
 *
 * 给你一个正整数的数组 A（其中的元素不一定完全不同），请你返回可在 一次交换（交换两数字 A[i] 和 A[j] 的位置）后得到的、按字典序排列小于 A
 * 的最大可能排列。
 *
 * 如果无法这么操作，就请返回原数组。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：arr = [3,2,1]
 * 输出：[3,1,2]
 * 解释：交换 2 和 1
 *
 *
 * 示例 2：
 *
 *
 * 输入：arr = [1,1,5]
 * 输出：[1,1,5]
 * 解释：已经是最小排列
 *
 *
 * 示例 3：
 *
 *
 * 输入：arr = [1,9,4,6,7]
 * 输出：[1,7,4,6,9]
 * 解释：交换 9 和 7
 *
 *
 * 示例 4：
 *
 *
 * 输入：arr = [3,1,1,3]
 * 输出：[1,3,1,3]
 * 解释：交换 1 和 3
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * 1
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> prevPermOpt1(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = n - 1; i > 0; --i)
        {
            if (arr[i - 1] > arr[i])
            {
                int x = i - 1;
                int y = n - 1;
                int maxn = 0;
                for (int j = n - 1; j > x; --j)
                {
                    if (arr[j] < arr[x])
                    {
                        if (maxn <= arr[j])
                        {
                            maxn = arr[j];
                            y = j;
                        }
                    }
                }
                swap(arr[x], arr[y]);
                break;
            }
        }
        return arr;
    }
};
// @lc code=end
