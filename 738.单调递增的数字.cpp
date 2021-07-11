/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start
class Solution
{
public:
    int monotoneIncreasingDigits(int n)
    {
        string s = to_string(n);
        stack<char> stk;
        bool flag = false;
        for (char c : s)
        {
            if (stk.empty() || c >= stk.top())
                stk.push(c);
            else
            {
                char tmp = stk.top() - 1;
                stk.pop();
                while (!stk.empty() && tmp < stk.top())
                {
                    tmp = stk.top() - 1;
                    stk.pop();
                }
                stk.push(tmp);
                flag = true;
                break;
            }
        }
        if (flag)
        {
            string res;
            while (!stk.empty())
            {
                res += stk.top();
                stk.pop();
            }
            reverse(res.begin(), res.end());
            for (int i = res.size(); i < s.size(); ++i)
            {
                res += '9';
            }
            return stoi(res);
        }
        return n;
    }
};
// @lc code=end
