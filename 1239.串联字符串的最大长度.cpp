/*
 * @lc app=leetcode.cn id=1239 lang=cpp
 *
 * [1239] 串联字符串的最大长度
 *
 * https://leetcode.cn/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/
 *
 * algorithms
 * Medium (48.90%)
 * Likes:    202
 * Dislikes: 0
 * Total Accepted:    37.5K
 * Total Submissions: 76.8K
 * Testcase Example:  '["un","iq","ue"]'
 *
 * 给定一个字符串数组 arr，字符串 s 是将 arr 的含有 不同字母 的 子序列 字符串 连接 所得的字符串。
 *
 * 请返回所有可行解 s 中最长长度。
 *
 * 子序列 是一种可以从另一个数组派生而来的数组，通过删除某些元素或不删除元素而不改变其余元素的顺序。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：arr = ["un","iq","ue"]
 * 输出：4
 * 解释：所有可能的串联组合是：
 * - ""
 * - "un"
 * - "iq"
 * - "ue"
 * - "uniq" ("un" + "iq")
 * - "ique" ("iq" + "ue")
 * 最大长度为 4。
 *
 *
 * 示例 2：
 *
 *
 * 输入：arr = ["cha","r","act","ers"]
 * 输出：6
 * 解释：可能的解答有 "chaers" 和 "acters"。
 *
 *
 * 示例 3：
 *
 *
 * 输入：arr = ["abcdefghijklmnopqrstuvwxyz"]
 * 输出：26
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= arr.length <= 16
 * 1 <= arr[i].length <= 26
 * arr[i] 中只含有小写英文字母
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int maxLength(vector<string> &arr)
    {
        int n = arr.size();
        vector<vector<int>> cnt(n, vector<int>(26, 0));
        vector<int> lenth(n, 0);
        for (int i = 0; i < n; ++i)
        {
            for (char c : arr[i])
            {
                if (cnt[i][c - 'a'] == 0)
                {
                    lenth[i]++;
                }
                cnt[i][c - 'a']++;
            }
        }
        int len = 1 << n;
        vector<vector<int>> dp(len, vector<int>(26, 0));
        vector<int> res(len, -2);
        int ans = 0;
        res[0] = 0;
        for (int i = 0; i < len; ++i)
        {
            if (-1 == res[i])
                continue;
            ans = max(ans, res[i]);
            for (int j = 0; j < n; ++j)
            {
                if (i & (1 << j))
                    continue;
                int k = i | (1 << j);
                if (-2 != res[k])
                    continue;
                res[k] = -1;
                bool flag = true;
                for (int t = 0; t < 26; ++t)
                {
                    dp[k][t] = dp[i][t] + cnt[j][t];
                    if (dp[k][t] > 1)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    res[k] = res[i] + lenth[j];
            }
        }
        return ans;
    }
};
// @lc code=end
