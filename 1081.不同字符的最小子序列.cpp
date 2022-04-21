/*
 * @lc app=leetcode.cn id=1081 lang=cpp
 *
 * [1081] 不同字符的最小子序列
 *
 * https://leetcode-cn.com/problems/smallest-subsequence-of-distinct-characters/description/
 *
 * algorithms
 * Medium (57.87%)
 * Likes:    142
 * Dislikes: 0
 * Total Accepted:    18.5K
 * Total Submissions: 32K
 * Testcase Example:  '"bcabc"'
 *
 * 返回 s 字典序最小的子序列，该子序列包含 s 的所有不同字符，且只包含一次。
 *
 * 注意：该题与 316 https://leetcode.com/problems/remove-duplicate-letters/ 相同
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "bcabc"
 * 输出："abc"
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "cbacdcbc"
 * 输出："acdb"
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * s 由小写英文字母组成
 *
 *
 */

// @lc code=start
class Solution
{
public:
    string smallestSubsequence(string s)
    {
        int n = s.size();
        stack<char> stk;
        vector<int> cnt(26, 0);
        vector<int> rest(26, 0);
        for (char c : s)
            rest[c - 'a']++;
        for (char c : s)
        {

            if (cnt[c - 'a'] == 0)
            {
                while ((!stk.empty()) && (stk.top() > c))
                {
                    if (rest[stk.top() - 'a'] > 0)
                    {
                        cnt[stk.top() - 'a']--;
                        stk.pop();
                    }
                    else
                        break;
                }
                stk.push(c);
                cnt[c - 'a']++;
            }
            rest[c - 'a']--;
        }
        string res;
        while (!stk.empty())
        {
            res.push_back(stk.top());
            stk.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
