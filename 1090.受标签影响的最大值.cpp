/*
 * @lc app=leetcode.cn id=1090 lang=cpp
 *
 * [1090] 受标签影响的最大值
 *
 * https://leetcode-cn.com/problems/largest-values-from-labels/description/
 *
 * algorithms
 * Medium (55.87%)
 * Likes:    24
 * Dislikes: 0
 * Total Accepted:    4.6K
 * Total Submissions: 8.2K
 * Testcase Example:  '[5,4,3,2,1]\n[1,1,2,2,3]\n3\n1'
 *
 * 我们有一个 n 项的集合。给出两个整数数组 values 和 labels ，第 i 个元素的值和标签分别是 values[i] 和
 * labels[i]。还会给出两个整数 numWanted 和 useLimit 。
 *
 * 从 n 个元素中选择一个子集 s :
 *
 *
 * 子集 s 的大小 小于或等于 numWanted 。
 * s 中 最多 有相同标签的 useLimit 项。
 *
 *
 * 一个子集的 分数 是该子集的值之和。
 *
 * 返回子集 s 的最大 分数 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：values = [5,4,3,2,1], labels = [1,1,2,2,3], numWanted = 3, useLimit = 1
 * 输出：9
 * 解释：选出的子集是第一项，第三项和第五项。
 *
 *
 * 示例 2：
 *
 *
 * 输入：values = [5,4,3,2,1], labels = [1,3,3,3,2], numWanted = 3, useLimit = 2
 * 输出：12
 * 解释：选出的子集是第一项，第二项和第三项。
 *
 *
 * 示例 3：
 *
 *
 * 输入：values = [9,8,8,7,6], labels = [0,0,0,1,1], numWanted = 3, useLimit = 1
 * 输出：16
 * 解释：选出的子集是第一项和第四项。
 *
 *
 *
 *
 * 提示：
 *
 *
 * n == values.length == labels.length
 * 1 <= n <= 2 * 10^4
 * 0 <= values[i], labels[i] <= 2 * 10^4
 * 1 <= numWanted, useLimit <= n
 *
 *
 */

// @lc code=start
class Solution
{
public:
    using pii = pair<int, int>;
    int largestValsFromLabels(vector<int> &values, vector<int> &labels, int numWanted, int useLimit)
    {
        int n = values.size();
        vector<pii> v2l(n);
        for (int i = 0; i < n; ++i)
        {
            v2l[i] = {values[i], labels[i]};
        }
        sort(v2l.begin(), v2l.end(), [](const auto &a, const auto &b)
             { return a.first > b.first; });

        map<int, int> l2cnt;
        int res = 0;
        int cnt = 0;
        for (auto &[v, l] : v2l)
        {
            if ((cnt < numWanted) && (l2cnt[l] < useLimit))
            {
                res += v;
                cnt++;
                l2cnt[l]++;
            }
        }
        return res;
    }
};
// @lc code=end
