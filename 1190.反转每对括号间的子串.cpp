/*
 * @lc app=leetcode.cn id=1190 lang=cpp
 *
 * [1190] 反转每对括号间的子串
 *
 * https://leetcode.cn/problems/reverse-substrings-between-each-pair-of-parentheses/description/
 *
 * algorithms
 * Medium (64.88%)
 * Likes:    232
 * Dislikes: 0
 * Total Accepted:    51.4K
 * Total Submissions: 79.2K
 * Testcase Example:  '"(abcd)"'
 *
 * 给出一个字符串 s（仅含有小写英文字母和括号）。
 *
 * 请你按照从括号内到外的顺序，逐层反转每对匹配括号中的字符串，并返回最终的结果。
 *
 * 注意，您的结果中 不应 包含任何括号。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：s = "(abcd)"
 * 输出："dcba"
 *
 *
 * 示例 2：
 *
 *
 * 输入：s = "(u(love)i)"
 * 输出："iloveu"
 * 解释：先反转子字符串 "love" ，然后反转整个字符串。
 *
 * 示例 3：
 *
 *
 * 输入：s = "(ed(et(oc))el)"
 * 输出："leetcode"
 * 解释：先反转子字符串 "oc" ，接着反转 "etco" ，然后反转整个字符串。
 *
 * 示例 4：
 *
 *
 * 输入：s = "a(bcdefghijkl(mno)p)q"
 * 输出："apmnolkjihgfedcbq"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * s 中只有小写英文字母和括号
 * 题目测试用例确保所有括号都是成对出现的
 *
 *
 */

// @lc code=start
class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<string> stk;
        int n = s.size();
        string tmp;
        for (int i = 0; i < n; ++i)
        {
            char c = s[i];
            if ('(' == c)
            {
                stk.push(tmp);
                tmp = "";
            }
            else if (')' == c)
            {
                reverse(tmp.begin(), tmp.end());
                tmp = stk.top() + tmp;
                stk.pop();
            }
            else
            {
                tmp += c;
            }
        }
        return tmp;
    }
};
// @lc code=end
