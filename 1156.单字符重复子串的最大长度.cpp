/*
 * @lc app=leetcode.cn id=1156 lang=cpp
 *
 * [1156] 单字符重复子串的最大长度
 *
 * https://leetcode.cn/problems/swap-for-longest-repeated-character-substring/description/
 *
 * algorithms
 * Medium (42.96%)
 * Likes:    88
 * Dislikes: 0
 * Total Accepted:    6.7K
 * Total Submissions: 15.7K
 * Testcase Example:  '"ababa"'
 *
 * 如果字符串中的所有字符都相同，那么这个字符串是单字符重复的字符串。
 *
 * 给你一个字符串 text，你只能交换其中两个字符一次或者什么都不做，然后得到一些单字符重复的子串。返回其中最长的子串的长度。
 *
 *
 *
 * 示例 1：
 *
 * 输入：text = "ababa"
 * 输出：3
 *
 *
 * 示例 2：
 *
 * 输入：text = "aaabaaa"
 * 输出：6
 *
 *
 * 示例 3：
 *
 * 输入：text = "aaabbaaa"
 * 输出：4
 *
 *
 * 示例 4：
 *
 * 输入：text = "aaaaa"
 * 输出：5
 *
 *
 * 示例 5：
 *
 * 输入：text = "abcdef"
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= text.length <= 20000
 * text 仅由小写英文字母组成。
 *
 *
 */

// @lc code=start
class Solution
{
public:
    int maxRepOpt1(string text)
    {
        int n = text.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        vector<int> cnt(26, 0);
        left[0] = 1;
        right[n - 1] = 1;
        int res = 1;
        for (int i = 0; i < n; ++i)
            cnt[text[i] - 'a']++;
        for (int i = 1; i < n; ++i)
        {
            if (text[i] == text[i - 1])
            {
                left[i] = left[i - 1] + 1;
            }
            else
                left[i] = 1;
        }
        for (int i = 0; i < n; ++i)
            res = max(res, min(left[i] + 1, cnt[text[i] - 'a']));

        for (int i = n - 2; i >= 0; --i)
            if (text[i] == text[i + 1])
                right[i] = right[i + 1] + 1;
            else
                right[i] = 1;
        for (int i = 1; i < n - 1; ++i)
        {
            if (text[i - 1] == text[i])
                continue;
            if (text[i - 1] == text[i + 1])
            {
                res = max(res, min(left[i - 1] + right[i + 1] + 1, cnt[text[i - 1] - 'a']));
            }
        }
        return res;
    }
};
// @lc code=end
