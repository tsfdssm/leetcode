/*
 * @lc app=leetcode.cn id=1106 lang=cpp
 *
 * [1106] 解析布尔表达式
 *
 * https://leetcode-cn.com/problems/parsing-a-boolean-expression/description/
 *
 * algorithms
 * Hard (58.57%)
 * Likes:    58
 * Dislikes: 0
 * Total Accepted:    4.9K
 * Total Submissions: 8.3K
 * Testcase Example:  '"!(f)"'
 *
 * 给你一个以字符串形式表述的 布尔表达式（boolean） expression，返回该式的运算结果。
 *
 * 有效的表达式需遵循以下约定：
 *
 *
 * "t"，运算结果为 True
 * "f"，运算结果为 False
 * "!(expr)"，运算过程为对内部表达式 expr 进行逻辑 非的运算（NOT）
 * "&(expr1,expr2,...)"，运算过程为对 2 个或以上内部表达式 expr1, expr2, ... 进行逻辑 与的运算（AND）
 * "|(expr1,expr2,...)"，运算过程为对 2 个或以上内部表达式 expr1, expr2, ... 进行逻辑 或的运算（OR）
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：expression = "!(f)"
 * 输出：true
 *
 *
 * 示例 2：
 *
 * 输入：expression = "|(f,t)"
 * 输出：true
 *
 *
 * 示例 3：
 *
 * 输入：expression = "&(t,f)"
 * 输出：false
 *
 *
 * 示例 4：
 *
 * 输入：expression = "|(&(t,f,t),!(t))"
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= expression.length <= 20000
 * expression[i] 由 {'(', ')', '&', '|', '!', 't', 'f', ','} 中的字符组成。
 * expression 是以上述形式给出的有效表达式，表示一个布尔值。
 *
 *
 */

// @lc code=start
class Solution
{
public:
    bool solve(string &s, int left, int right)
    {
        if (s[left] == 'f')
            return false;
        if (s[left] == 't')
            return true;
        if (s[left] == '!')
        {
            return !solve(s, left + 2, right - 1);
        }
        if (s[left] == '&')
        {
            int balance = 0;
            for (int i = left + 2; i <= right - 1;)
            {
                int j = i;
                while (j < right && (s[j] != ',' || balance > 0))
                {
                    balance += s[j] == '(';
                    balance -= s[j] == ')';
                    ++j;
                }
                if (!solve(s, i, j - 1))
                    return false;
                i = j + 1;
            }
            return true;
        }
        if (s[left] == '|')
        {
            int balance = 0;
            for (int i = left + 2; i <= right - 1;)
            {
                int j = i;
                while (j < right && (s[j] != ',' || balance > 0))
                {
                    balance += s[j] == '(';
                    balance -= s[j] == ')';
                    ++j;
                }
                if (solve(s, i, j - 1))
                    return true;
                i = j + 1;
            }
            return false;
        }
        return false;
    }
    bool parseBoolExpr(string exp)
    {
        return solve(exp, 0, exp.size() - 1);
    }
};
// @lc code=end
