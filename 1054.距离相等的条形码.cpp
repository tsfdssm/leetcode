/*
 * @lc app=leetcode.cn id=1054 lang=cpp
 *
 * [1054] 距离相等的条形码
 *
 * https://leetcode-cn.com/problems/distant-barcodes/description/
 *
 * algorithms
 * Medium (38.67%)
 * Likes:    80
 * Dislikes: 0
 * Total Accepted:    9.1K
 * Total Submissions: 23.5K
 * Testcase Example:  '[1,1,1,2,2,2]'
 *
 * 在一个仓库里，有一排条形码，其中第 i 个条形码为 barcodes[i]。
 *
 * 请你重新排列这些条形码，使其中任意两个相邻的条形码不能相等。 你可以返回任何满足该要求的答案，此题保证存在答案。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：barcodes = [1,1,1,2,2,2]
 * 输出：[2,1,2,1,2,1]
 *
 *
 * 示例 2：
 *
 *
 * 输入：barcodes = [1,1,1,1,2,2,3,3]
 * 输出：[1,3,1,3,2,1,2,1]
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= barcodes.length <= 10000
 * 1 <= barcodes[i] <= 10000
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> rearrangeBarcodes(vector<int> &barcodes)
    {
        int n = barcodes.size();
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> pq;
        vector<int> res(n);
        for (int num : barcodes)
            mp[num]++;

        for (auto [num, cnt] : mp)
        {
            int t = cnt;
            while (t--)
                pq.push({cnt, num});
        }

        for (int i = 0; i < n; i += 2)
        {
            res[i] = pq.top().second;
            pq.pop();
        }
        for (int i = 1; i < n; i += 2)
        {
            res[i] = pq.top().second;
            pq.pop();
        }
        return res;
    }
};
// @lc code=end
