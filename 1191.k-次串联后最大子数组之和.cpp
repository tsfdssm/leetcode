/*
 * @lc app=leetcode.cn id=1191 lang=cpp
 *
 * [1191] K 次串联后最大子数组之和
 *
 * https://leetcode.cn/problems/k-concatenation-maximum-sum/description/
 *
 * algorithms
 * Medium (26.76%)
 * Likes:    95
 * Dislikes: 0
 * Total Accepted:    7K
 * Total Submissions: 26K
 * Testcase Example:  '[1,2]\n3'
 *
 * 给定一个整数数组 arr 和一个整数 k ，通过重复 k 次来修改数组。
 *
 * 例如，如果 arr = [1, 2] ， k = 3 ，那么修改后的数组将是 [1, 2, 1, 2, 1, 2] 。
 *
 * 返回修改后的数组中的最大的子数组之和。注意，子数组长度可以是 0，在这种情况下它的总和也是 0。
 *
 * 由于 结果可能会很大，需要返回的 10^9 + 7 的 模 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：arr = [1,2], k = 3
 * 输出：9
 *
 *
 * 示例 2：
 *
 *
 * 输入：arr = [1,-2,1], k = 5
 * 输出：2
 *
 *
 * 示例 3：
 *
 *
 * 输入：arr = [-1,-2], k = 7
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 *
 * 1 <= arr.length <= 10^5
 * 1 <= k <= 10^5
 * -10^4 <= arr[i] <= 10^4
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int kConcatenationMaxSum(vector<int> &arr, int k)
    {
        int maxnn = *max_element(arr.begin(), arr.end());
        if (maxnn <= 0)
            return 0;
        long long sum = 0;
        long long maxn = 0;
        if (k == 1)
        {
            for (int num : arr)
            {
                sum = num + max(0LL, sum);
                maxn = max(maxn, sum);
            }
            return maxn;
        }
        const int mod = 1e9 + 7;
        vector<int> vec = arr;
        vec.insert(vec.end(), arr.begin(), arr.end());
        long long total = accumulate(arr.begin(), arr.end(), 0LL);
        sum = 0;
        maxn = 0;
        for (int num : vec)
        {
            sum = num + max(0LL, sum);
            maxn = max(maxn, sum);
        }
        if (total <= 0)
        {
            return maxn % mod;
        }
        return (maxn + (k - 2) * total) % mod;
    }
};
// @lc code=end
