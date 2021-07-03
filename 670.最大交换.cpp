/*
 * @lc app=leetcode.cn id=670 lang=cpp
 *
 * [670] 最大交换
 */

// @lc code=start
class Solution
{
public:
    int maximumSwap(int num)
    {
        string s = to_string(num);
        int n = s.size();
        int st = 1;
        while (st < n)
        {
            if (s[st] > s[st - 1])
                break;
            ++st;
        }
        if (n == st)
            return num;
        int idx = st++;
        while (st < n)
        {
            if (s[st] >= s[idx])
                idx = st;
            st++;
        }
        int ed = st = idx;
        while (idx >= 0)
        {
            if (s[idx] < s[st])
                ed = idx;
            idx--;
        }
        swap(s[st], s[ed]);
        return stoi(s);
    }
};
// @lc code=end
