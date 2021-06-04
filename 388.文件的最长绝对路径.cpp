/*
 * @lc app=leetcode.cn id=388 lang=cpp
 *
 * [388] 文件的最长绝对路径
 */

// @lc code=start
class Solution
{
public:
    int lengthLongestPath(string input)
    {
        string name;
        bool isfile = false;

        stack<string> stk;
        int tmp = 0;
        int res = 0;
        input.push_back('\n');
        int n = input.size();
        for (int i = 0; i < n; ++i)
        {
            char c = input[i];
            if ('\n' == c)
            {
                if (isfile)
                {
                    isfile = false;
                    res = max(tmp + (int)name.size(), res);
                }
                else
                {
                    tmp += name.size() + 1;
                    stk.push(name);
                }
                name.clear();
                int j = i + 1;
                while (j < n && input[j] == '\t')
                    ++j;

                int cnt = j - i - 1;
                i = j - 1;
                while (stk.size() > cnt)
                {
                    tmp -= (stk.top().size() + 1);
                    stk.pop();
                }
            }
            else
            {
                if ('.' == c)
                {
                    isfile = true;
                }
                name += c;
            }
        }
        return res;
    }
};
// @lc code=end
