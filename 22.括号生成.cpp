/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        string current;
        vector<string> res;
        backtrack(res, current, 0, 0, n);
        return res;
    }
    void backtrack(vector<string> &res, string &cur, int open, int close, int n)
    {
        if (cur.size() == n * 2)
        {
            res.push_back(cur);
            return;
        }
        else if (open < n)
        {
            cur.push_back('(');
            backtrack(res, cur, open + 1, close, n);
            cur.pop_back();
        }
        if (close < open)
        {
            cur.push_back(')');
            backtrack(res, cur, open, close + 1, n);
            cur.pop_back();
        }
    }
};
// @lc code=end
