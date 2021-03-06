/*
 * @lc app=leetcode.cn id=1187 lang=cpp
 *
 * [1187] 使数组严格递增
 *
 * https://leetcode.cn/problems/make-array-strictly-increasing/description/
 *
 * algorithms
 * Hard (46.17%)
 * Likes:    82
 * Dislikes: 0
 * Total Accepted:    2.4K
 * Total Submissions: 5.2K
 * Testcase Example:  '[1,5,3,6,7]\n[1,3,2,4]'
 *
 * 给你两个整数数组 arr1 和 arr2，返回使 arr1 严格递增所需要的最小「操作」数（可能为 0）。
 *
 * 每一步「操作」中，你可以分别从 arr1 和 arr2 中各选出一个索引，分别为 i 和 j，0 <= i < arr1.length 和 0 <= j
 * < arr2.length，然后进行赋值运算 arr1[i] = arr2[j]。
 *
 * 如果无法让 arr1 严格递增，请返回 -1。
 *
 *
 *
 * 示例 1：
 *
 * 输入：arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
 * 输出：1
 * 解释：用 2 来替换 5，之后 arr1 = [1, 2, 3, 6, 7]。
 *
 *
 * 示例 2：
 *
 * 输入：arr1 = [1,5,3,6,7], arr2 = [4,3,1]
 * 输出：2
 * 解释：用 3 来替换 5，然后用 4 来替换 3，得到 arr1 = [1, 3, 4, 6, 7]。
 *
 *
 * 示例 3：
 *
 * 输入：arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
 * 输出：-1
 * 解释：无法使 arr1 严格递增。
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= arr1.length, arr2.length <= 2000
 * 0 <= arr1[i], arr2[i] <= 10^9
 *
 *
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
    {
        int m = arr1.size();

        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        int n = arr2.size();
        int len = min(m, n);
        const int inf = 0x3f3f3f3f;
        vector<vector<int>> dp(m, vector<int>(len + 1, inf));

        dp[0][0] = arr1[0];
        dp[0][1] = min(arr1[0], arr2[0]);

        for (int i = 1; i < m; ++i)
        {
            if (arr1[i] > arr1[i - 1])
                dp[i][0] = arr1[i];
            else
                break;
        }
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j <= len && j <= (i + 1); ++j)
            {
                dp[i][j] = dp[i][j - 1];
                if (arr1[i] > dp[i - 1][j])
                    dp[i][j] = min(arr1[i], dp[i][j]);
                auto p = upper_bound(arr2.begin(), arr2.end(), dp[i - 1][j - 1]);
                if (p == arr2.end())
                    continue;
                dp[i][j] = min(dp[i][j], *p);
            }
        }

        for (int i = 0; i <= len; ++i)
        {
            if (inf != dp[m - 1][i])
                return i;
        }
        return -1;
    }
};
// @lc code=end
