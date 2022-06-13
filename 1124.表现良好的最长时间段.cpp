/*
 * @lc app=leetcode.cn id=1124 lang=cpp
 *
 * [1124] 表现良好的最长时间段
 *
 * https://leetcode.cn/problems/longest-well-performing-interval/description/
 *
 * algorithms
 * Medium (33.27%)
 * Likes:    185
 * Dislikes: 0
 * Total Accepted:    16K
 * Total Submissions: 48.1K
 * Testcase Example:  '[9,9,6,0,6,6,9]'
 *
 * 给你一份工作时间表 hours，上面记录着某一位员工每天的工作小时数。
 *
 * 我们认为当员工一天中的工作小时数大于 8 小时的时候，那么这一天就是「劳累的一天」。
 *
 * 所谓「表现良好的时间段」，意味在这段时间内，「劳累的天数」是严格 大于「不劳累的天数」。
 *
 * 请你返回「表现良好时间段」的最大长度。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：hours = [9,9,6,0,6,6,9]
 * 输出：3
 * 解释：最长的表现良好时间段是 [9,9,6]。
 *
 * 示例 2：
 *
 *
 * 输入：hours = [6,6,6]
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= hours.length <= 10^4
 * 0 <= hours[i] <= 16
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int longestWPI(vector<int> &hours)
    {
        int n = hours.size();
        int cnt = 0;
        int res = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < n; ++i)
        {
            cnt += hours[i] > 8 ? 1 : -1;
            if (mp.count(cnt - 1))
                res = max(res, i - mp[cnt - 1]);
            if (cnt > 0)
                res = max(res, i + 1);
            if (!mp.count(cnt))
                mp[cnt] = i;
        }
        return res;
    }
};
// @lc code=end
