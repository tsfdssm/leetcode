/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
class Solution
{
public:
    vector<int> diffWaysToCompute(const string &s)
    {
        vector<int> res;
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            if ('+' == s[i] || '-' == s[i] || '*' == s[i])
            {
                vector<int> left = diffWaysToCompute(s.substr(0, i));
                vector<int> right = diffWaysToCompute(s.substr(i + 1));
                for (int j : left)
                    for (int k : right)
                    {
                        if ('+' == s[i])
                        {
                            res.push_back(j + k);
                        }
                        else if ('-' == s[i])
                        {
                            res.push_back(j - k);
                        }
                        else
                        {
                            res.push_back(j * k);
                        }
                    }
            }
        }
        if (res.empty())
            res.push_back(stoi(s));
        return res;
    }
};
// @lc code=end
