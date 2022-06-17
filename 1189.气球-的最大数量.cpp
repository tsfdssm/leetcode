/*
 * @lc app=leetcode.cn id=1189 lang=cpp
 *
 * [1189] “气球” 的最大数量
 *
 * https://leetcode.cn/problems/maximum-number-of-balloons/description/
 *
 * algorithms
 * Easy (68.63%)
 * Likes:    110
 * Dislikes: 0
 * Total Accepted:    53.5K
 * Total Submissions: 77.9K
 * Testcase Example:  '"nlaebolko"'
 *
 * 给你一个字符串 text，你需要使用 text 中的字母来拼凑尽可能多的单词 "balloon"（气球）。
 *
 * 字符串 text 中的每个字母最多只能被使用一次。请你返回最多可以拼凑出多少个单词 "balloon"。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：text = "nlaebolko"
 * 输出：1
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：text = "loonbalxballpoon"
 * 输出：2
 *
 *
 * 示例 3：
 *
 * 输入：text = "leetcode"
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= text.length <= 10^4
 * text 全部由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        string target = "balloon";
        vector<int> t(26, 0);
        vector<int> cnt(26, 0);
        for (char c : text)
            cnt[c - 'a']++;
        for (char c : target)
            t[c - 'a']++;
        int res = 1e4;
        for (int i = 0; i < 26; ++i)
        {
            if (t[i] != 0)
            {
                if (cnt[i] == 0)
                    return 0;
                res = min(res, cnt[i] / t[i]);
            }
        }
        return res;
    }
};
// @lc code=end
