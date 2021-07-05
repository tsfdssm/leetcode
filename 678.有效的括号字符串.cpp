/*
 * @lc app=leetcode.cn id=678 lang=cpp
 *
 * [678] 有效的括号字符串
 */

// @lc code=start
class Solution
{
public:
    bool checkValidString(const string &s)
    {
        int cnt = 0;
        int pcntl = 0;
        int pcntr = 0;
        for (char c : s)
        {
            if (c == '(')
            {
                cnt++;
            }
            else if (c == ')')
            {
                cnt--;
            }
            else
            {
                pcntr++;
                pcntl++;
            }
            if (cnt < pcntr)
                pcntr = cnt;
            if (pcntl + cnt < 0)
                return false;
        }
        return cnt <= pcntr;
    }
};
// @lc code=end
